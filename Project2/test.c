#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int age = 0;
	scanf("%d", &age);
	if (age < 18)
	{
		printf("����\n");
	}
	else if (age >= 18 && age < 30)
	{
		printf("����\n");
	}
	else if (age >= 30 && age < 50)
	{
		printf("����\n");
	}
	else if (age >= 50 && age < 80)
	{
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}

}