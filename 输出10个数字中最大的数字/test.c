#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	int max;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		if (i == 0)
		{
			max = arr[0];
		}
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	printf("%d", max);
}