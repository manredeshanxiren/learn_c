#define _CRT_SECURE_NO_WARNINGS 1
#include"mine.h"
void menu()
{
	printf("****************************************\n");
	printf("*********1.play          0.exit  *******\n");
	printf("****************************************\n");
	printf("****************************************\n");
}
int main()
{
	int input = 0;
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
		case 0:
			printf("�˳�");
			break;
		default:
			printf("����������������룡");
			break;
		}
	} while (input);
	return 0;
}