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
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("��Ϸ�˳���");
				break;
			default:
				printf("����������������룡");
				break;
		}
	} while (input);
	return 0;
}