#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 0;
	scanf("%d", &k);
	int left = 0;
	int right = 9;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (k < arr[mid])
		{
			right = mid - 1;
		}
		else if (k > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了！下标为:%d",mid);
			return 1;
			break;
		}
	}
	printf("没找到");
}