#define _CRT_SECURE_NO_WARNINGS 1
//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//
//例如：2 + 22 + 222 + 2222 + 22222
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < 5; i++)
	{
		sum += pow(10, i) * n * (5 - i);
	}
	printf("%d", sum);
}