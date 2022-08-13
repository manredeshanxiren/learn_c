#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define DEFAULT_SIZE 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

//��Ϸ����
void game();


//�����ʼ������
void reset(char arr[ROWS][COLS], int row, int col, char ans);

//��ӡ����
void DisplayArr(char arr[ROWS][COLS], int row, int col);


//������
void SetMine(char mine[ROWS][COLS], int row, int col);

//����
void FindMine(char mine[ROWS][COLS], char clear[ROWS][COLS], int row, int col);

//����׵ĸ���
int GetMineCount(char mine[ROWS][COLS], int x, int y);