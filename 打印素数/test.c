#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int JudgePrime(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	for (int i = 101; i <= 200; i += 2)
	{
		if (JudgePrime(i) == 1)
		{
			printf("%d ", i);
		}
	}
}