#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int cacu(int n)
{
	int count = 0;
	int temp = 0;
	while (n / 2)
	{
		if (n % 2 == 1)
			temp++;
		count += n / 2;
		n = n / 2;
	}
	if (n == 1)
		temp++;
	if (temp / 2 == 0)
	{
		return count;
	}
	else
	{
		return count + cacu(temp);
	}
}
int main()
{
	int n;
	int count = 0;
	scanf_s("%d", &n);
	count += n;
	printf("%d", count + cacu(n));
	return 0;
}