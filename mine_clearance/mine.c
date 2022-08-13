#define _CRT_SECURE_NO_WARNINGS 1

#include"mine.h"


//����׵ĸ���
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x - 1][y] +
		mine[x + 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] - 8 * '0';
}

//����
void FindMine(char mine[ROWS][COLS], char clear[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - DEFAULT_SIZE)
	{
		printf("������Ҫ�Ų��׵�����:>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (clear[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					DisplayArr(mine, ROW, COL);
					break;
				}
				else
				{
					int count = GetMineCount(mine, x, y);
					clear[x][y] = count + '0';
					system("cls");
					DisplayArr(clear, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("�������Ѿ����Ų����\n");
			}
		}
		else
		{
			printf("����Ƿ�������������:>");
		}
	}
	if (win == row * col - DEFAULT_SIZE)
	{
		printf("��ϲ�����׳ɹ���\n");
		DisplayArr(mine, ROW, COL);
	}

}
//������
void SetMine(char arr[ROWS][COLS], int row, int col)
{
	//����10����
	int count = DEFAULT_SIZE;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}

}

//��ӡ����
void DisplayArr(char arr[ROWS][COLS], int row, int col)
{
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
		printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}


//�����ʼ������
void reset(char arr[ROWS][COLS], int rows, int cols, char ans)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = ans;
		}
	}
}
//��Ϸ����
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char clear[ROWS][COLS] = { 0 };

	//��ʼ������
	reset(mine, ROWS, COLS, '0');
	reset(clear, ROWS, COLS, '*');
	//������
	SetMine(mine, ROW, COL);
	//DisplayArr(mine, ROW, COL);
	DisplayArr(clear, ROW, COL);

	//����
	FindMine(mine, clear, ROW, COL);

}