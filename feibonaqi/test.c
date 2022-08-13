#define _CRT_SECURE_NO_WARNINGS 1
//非递归求斐波那契数
#include<stdio.h>
long feibo(int n)
{
	long a = 1;
	long b = 1;
	long c = 1;
	if (n <= 2)
	{
		return c;
	}
	else
	{
		while (n >= 3)
		{
			c = a + b;
			a = b;
			b = c;
			n--;
		}
		return c;
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%ld", feibo(n));
}