#define _CRT_SECURE_NO_WARNINGS 1
#define AVER 101920
#include<stdio.h>
int main()
{
	int arr[50];
	double sum = 0;
	for (int i = 0; i < 50; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sum = (sum * 1.0) / 50;
	if(sum == AVER)
	printf("相等");
	else
	{
		printf("不相等");
	}
	return 0;
}