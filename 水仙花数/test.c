#define _CRT_SECURE_NO_WARNINGS 1
//打印水仙花数
#include<stdio.h>
#include<math.h>
int Judge(int n)
{
	if (n <= 9)
	{
		return 1;
	}
	else
	{
		return 1 + Judge(n / 10);
	}
}
int Judgenum(int n, int ret)
{
	int sum = 0;
	for (int i = 0; i < ret; i++)
	{
		sum += pow(n % 10, ret);
		n = n / 10;
	}
	return sum;
}

int main()
{
	int ret = 0;
	//首先判断是几位数
	for (int i = 0; i <= 100000; i++)
	{
		ret = Judge(i);
		if (i == Judgenum(i, ret))
		{
			printf("%d  ", i);
		}
	}

}