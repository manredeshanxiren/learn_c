#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
//�������ʼ��
void resetarr(char arr [ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

//��ӡ����
void display(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//�������
void player(char arr[ROW][COL])
{
	int x = 0, y = 0;
	while (1)
	{
		printf("��������:>");
		scanf_s("%d %d", &x, &y);
		if (x <= ROW && y <= COL && x > 0 && y > 0  && arr[x - 1][y - 1] == ' ')
		{
			arr[x - 1][y - 1] = '*';
			break;
		}
		else 
		{
			printf("�����������������:\n");
		}
	}
}

//��������
void computer(char arr[ROW][COL])
{
	
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (arr[x][y] == ' ' && arr[x][y] != '*')
		{
			arr[x][y] = '#';
			break;
		}

	}

}

//�ж���Ӯ
int dgame(char arr[ROW][COL])//�;�
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
int judge(char arr[ROW][COL])
{
	//�ж���
	for (int i = 0; i < ROW; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == '*')
		{
			printf("���Ӯ��\n");
			return 1;
			break;
		}
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == '#')
		{
			printf("����Ӯ��\n");
			return 1;
			break;
		}
	}
	//�ж���
	 for (int i = 0; i < COL; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] == '*')
		{
			printf("���Ӯ��\n");
			return 1;
			break;
		}
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] == '#')
		{
			printf("����Ӯ��\n");
			return 1;
			break;
		}
	}
	//�ж�б��
	 if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
	 {
		 if (arr[1][1] == '#')
		 {
			 printf("����Ӯ��\n");
			 return 1;
		 }
		 else if (arr[1][1] == '*')
		 {
			 printf("���Ӯ��\n");
			 return 1;
		 }
	 }
	 else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
	 {
		 if (arr[1][1] == '#')
		 {
			 printf("����Ӯ��\n");
			 return 1;
		 }
		 else if (arr[1][1] == '*')
		 {
			 printf("���Ӯ��\n");
			 return 1;
		 }
	 }
	 else if (1 == dgame(arr))
	 {
		 printf("�;� \n");
		 return 1;
	 }
	 return 0;
}
void game()
{
	char arr[ROW][COL];
	resetarr(arr);
	display(arr, ROW, COL);
	while (1)
	{
		//�غϿ�ʼ
		player(arr);
		system("cls");
		display(arr, ROW, COL);
		if (1 == judge(arr))
		{
			break;
		}


		computer(arr);
		system("cls");
		display(arr, ROW, COL);
		if (1 == judge(arr))
		{
			break;
		}
	}
}

