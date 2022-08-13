#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu()
{
	printf("***************************************\n");
	printf("*********1.PLAY      0.EXIT   *********\n");
	printf("***************************************\n");
	printf("***************************************\n");
}

int main()
{
	int input = 0;
	do
	{
		menu();
		srand((unsigned int)time(NULL));
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("游戏退出！");
				break;
			default:
				printf("输入错误，请重新输入！");
				break;
		}
	} while (input);
	return 0;
}