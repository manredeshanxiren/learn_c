#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
long fact(int n)
{
	long sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum *= i;
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%ld", fact(n));
	return 0;
}