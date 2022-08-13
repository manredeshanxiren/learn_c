#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
double MyPow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if(k > 0)
	{
		return n * MyPow(n, k - 1);
	}
	else if (k < 0)
	{
		return (1.0 / n) * MyPow(n, k + 1);
	}
}
int main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);
	printf("%g", MyPow(n, k));
}