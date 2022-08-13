#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int fact(int i)
{
	if (i == 1)
		return 1;
	else
		return i * fact(i - 1);
}
int main()
{
	int i = 1;
	long sum = 0;
	int n = 0;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum += fact(i);
	}
	printf("%ld", sum);
}