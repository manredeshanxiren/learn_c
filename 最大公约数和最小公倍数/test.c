#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//计算最小公倍数
Common(int a, int b)
{
	int max = (a > b ? a : b);
	for (int i = max; i <= a * b; i++)
	{
		if ((i % a == 0) && (i % b == 0))
		{
			return i;
		}
	}
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", Common(a, b));
}