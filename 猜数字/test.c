#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("**********************************\n");
	printf("****   1.Play        0.Exit   ****\n");
	printf("**********************************\n");
}
void game()
{
	int gue;
	int num = rand() % 100 + 1;//生成1-100的数字
	while (1)
	{
		printf("请输入数字:>");
		scanf_s("%d", &gue);
		if (gue < num)
		{
			printf("太小了\n");
		}
		else if (gue > num)
		{
			printf("太大了\n");
		}
		else if (gue == num)
		{
			printf("猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	//随机数生成
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请输入:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1: 
			game();
			break;
		case 2:
			;
			break;
		default:
			printf("输入错误，请重新输入:>");
			break;
		}

	} while (input);
}