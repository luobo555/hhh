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
            scanf("%lld", &dis[i][j]);              //�������ݣ���ʾi��j���о���

    int S = 1 << (n - 1);                           //S��n-1��0�ֱ��ʾ�����Ʊ�ʾ1��n-1�ĳ����Ƿ��ڼ�����
    long long dp[n][S];                             //dp[i][j]:��ʾ��0���г�����������j���У�������i�����У�ע�⼯��j��û��i
    for (i = 1; i < n; i++)
        dp[i][0] = dis[0][i];                       //dp[i][0]:��ʾ��0���г�����i���У���û�о�����ĳ���
    for (j = 1; j < S; j++) {
        for (i = 1; i < n; i++) {
            long long Minij = inf;
            if (((1 << (i - 1)) & j) == 0) {        //���i�Ƿ���j�����У�Ŀ������û�о����ĳ���
            /*
                ����ѭ������min(�Ӽ���j���Ѿ����ڵĳ��е�i���м���ԭ���߹��ľ���)
            */
                for (k = 1; k < n; k++) {
                    if (((1 << (k - 1)) & j) != 0) {//���k�Ƿ��ڼ����У�Ŀ�����ҵ��Ѿ��߹��ĳ���
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
        temp = dis[i][0] + dp[i][S - 1 - (1 << (i - 1))];   //ѡ��һ�����лص�0�����У�������Сֵ
        if (ans > temp)
            ans = temp;
    }
    dp[0][S - 1] = ans;
    printf("%lld\n", ans);
    return 0;
}