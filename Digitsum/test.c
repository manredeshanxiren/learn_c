#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Digitsum(int n)
{
	if (n <= 9)
		return n;
	else
		return (n % 10) + Digitsum(n / 10);
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", Digitsum(n));
}