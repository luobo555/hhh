#include<stdio.h>
#include<string.h>
#define N_max 1000001
typedef long long int lli;

/*********************************************************************
输入：arr：		原数组基址。
      msbeg：	待排序部分首地址（含）。
      msend：	待排序部分末地址（含）。
返回：无。
功能：归并排序。对arr进行原地非降序稳定排序，通过指针arr传回主函数。
**********************************************************************/
void MergeSort(lli *arr, int msbeg, int msend)
{
	//当前待排序元素个数不大于1的特殊情况；当前待排序元素个数等于1的情况作为递归基础。
	if(msbeg >= msend){
		return;
	} else if (msend - msbeg == 1) {
		if(arr[msbeg] > arr[msend]) {
			lli temp = arr[msbeg];
			arr[msbeg] = arr[msend];
			arr[msend] = temp;
		}
		return;
	}
	//分解
	int mid = (msbeg + msend) >> 1;
	MergeSort(arr, msbeg, mid);
	MergeSort(arr, mid + 1, msend);
	//合并
	static lli arr_sub[N_max];
	memcpy(arr_sub + msbeg, arr + msbeg, (msend - msbeg + 1) * sizeof(lli));		
	lli *p_sub_former_tail = arr_sub + mid + 1, *p_sub_latter_tail = arr_sub + msend + 1;
	lli *p_sub_former = arr_sub + msbeg, *p_sub_latter = arr_sub + mid + 1;
	lli *p_pre = arr + msbeg;
	while(p_sub_former < p_sub_former_tail && p_sub_latter < p_sub_latter_tail) { //两路归并
		if(*p_sub_former < *p_sub_latter) {
			*p_pre++ = *p_sub_former++;
		} else if (*p_sub_former > *p_sub_latter) {
			*p_pre++ = *p_sub_latter++;
		} else {
			*p_pre++ = *p_sub_former++;
			*p_pre++ = *p_sub_latter++;
		}
	}
	while(p_sub_former < p_sub_former_tail) { //复制前半部分剩余元素（每次递归时，这个while与下面的while最多执行1个）。具体实现可用if判断+memcpy替代。
		*p_pre++ = *p_sub_former++;
	}
	while(p_sub_latter < p_sub_latter_tail) { //复制后半部分剩余元素。具体实现可用if判断+memcpy替代。
		*p_pre++ = *p_sub_latter++;
	}
}

int main()
{
	//变量定义及输入部分
	int n;
	lli arr[N_max];
	scanf("%d", &n);
	{
		int n_sub=n;
		while(n_sub-- > 0) {
			scanf("%lld", arr + n_sub);
		}
	}
	//排序
	MergeSort(arr, 0, n - 1);
	//输出结果
	if(n > 0) {
		printf("%lld", arr[0]);
	}
	{
		int i=1;
		while(i < n) {
			printf(" %lld", arr[i++]);
		}
	}
	printf("\n");
	return 0;
}

/*
Sample:
input:
6
3 2 5 1 4 3
output:
1 2 3 4 5 6
*/
