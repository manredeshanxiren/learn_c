#define _CRT_SECURE_NO_WARNINGS 1
//打印菱形
#include<stdio.h>
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		//先打印空格
		for (int j = ((n / 2) > i ? i : (n - i) - 1); j < n / 2; j++)
		{
			printf(" ");
		} 
		//打印星号
		for (int j = (i > n / 2 ? 2 * (i - n / 2) + 1: (n - 2 * i)); j <= n; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
//(i > n / 2 ? (i):( n / 2 - i))