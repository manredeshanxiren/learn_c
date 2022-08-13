#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//有一只青蛙要跳上n级台阶，每次可以选择跳一个或者跳两个，求有n阶台阶时有多少中跳法

long qinwa(int n)
{
	if (n <= 1)
	{
		return 1;//如果台阶只有一阶只有一种方法
	}
	else
	{
		return qinwa(n - 1) + qinwa(n - 2);//因为n阶台阶可以变成n-1阶和n-2阶台阶方法的和所以直接返回；
	}
}
int main()
{
	int n;
	scanf_s("%d", &n);
	printf("%d", qinwa(n));
}