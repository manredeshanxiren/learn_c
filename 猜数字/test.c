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
	int num = rand() % 100 + 1;//����1-100������
	while (1)
	{
		printf("����������:>");
		scanf_s("%d", &gue);
		if (gue < num)
		{
			printf("̫С��\n");
		}
		else if (gue > num)
		{
			printf("̫����\n");
		}
		else if (gue == num)
		{
			printf("�¶���\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	//���������
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("������:>");
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
			printf("�����������������:>");
			break;
		}

	} while (input);
}