#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void JudgeYear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0))|| (year % 400 == 0))
	{
		printf("�����꣡");
	}
	else
	{
		printf("�������꣡");
	}
}
int main()
{
	int year;
	scanf("%d", &year);
	JudgeYear(year);
}