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

//游戏函数
void game();


//数组初始化函数
void reset(char arr[ROWS][COLS], int row, int col, char ans);

//打印棋盘
void DisplayArr(char arr[ROWS][COLS], int row, int col);


//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col);

//排雷
void FindMine(char mine[ROWS][COLS], char clear[ROWS][COLS], int row, int col);

//获得雷的个数
int GetMineCount(char mine[ROWS][COLS], int x, int y);