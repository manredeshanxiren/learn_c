#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
long feibona(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return feibona(n - 1) + feibona(n - 2);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%ld", feibona(n));
}