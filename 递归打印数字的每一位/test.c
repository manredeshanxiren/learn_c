#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void print(int n)
{
	if (n <= 9)
	{
		printf("%d ",n);
	}
	else
	{
		
		print(n / 10);
		printf("%d ", n % 10);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	print(n);
	return 0;
}