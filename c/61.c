#include <stdio.h>

#define inf  1e8

int main()
{
    int n;
    scanf("%d", &n);
    long long dis[n][n];
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lld", &dis[i][j]);              //输入数据，表示i到j城市距离

    int S = 1 << (n - 1);                           //S有n-1个0分别表示二进制表示1到n-1的城市是否在集合中
    long long dp[n][S];                             //dp[i][j]:表示从0城市出发经过集合j城市，现在在i城市中，注意集合j中没有i
    for (i = 1; i < n; i++)
        dp[i][0] = dis[0][i];                       //dp[i][0]:表示从0城市出发到i城市，还没有经过别的城市
    for (j = 1; j < S; j++) {
        for (i = 1; i < n; i++) {
            long long Minij = inf;
            if (((1 << (i - 1)) & j) == 0) {        //检查i是否在j集合中，目的是找没有经过的城市
            /*
                以下循环在找min(从集合j中已经存在的城市到i城市加上原来走过的距离)
            */
                for (k = 1; k < n; k++) {
                    if (((1 << (k - 1)) & j) != 0) {//检查k是否在集合中，目的是找到已经走过的城市
                        long long temp = dis[k][i] + dp[k][j - (1 << (k - 1))];
                        if (Minij > temp) Minij = temp;
                    }
                }
            }
            dp[i][j] = Minij;
        }
    }
    long long ans = inf;
    long long temp;
    for (i = 1; i < n; i++) {
        temp = dis[i][0] + dp[i][S - 1 - (1 << (i - 1))];   //选择一个城市回到0城市中，保留最小值
        if (ans > temp)
            ans = temp;
    }
    dp[0][S - 1] = ans;
    printf("%lld\n", ans);
    return 0;
}