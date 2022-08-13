#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//打印杨辉三角
int main()
{
	int n;
	int arr[100] = { 1 };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		//打印空格
		for (int j = 0; j < n - i; j++)
		{
			printf(" ");
		}
		//将数字进行运算
		for (int k = i - 1; k > 0; k--)
		{
			arr[k] = arr[k] + arr[k - 1];
		}
		//打印数字
		for (int z = 0; z < i; z++)
		{
			printf("%d ", arr[z]);
		}
		printf("\n");
	}

}