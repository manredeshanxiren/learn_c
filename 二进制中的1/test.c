#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����һ�����Ķ������м���1
int JudgeOne(int n)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (n & (1 << i))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	printf("%d", JudgeOne(n));
	return 0;
}