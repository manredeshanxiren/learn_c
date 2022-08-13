#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
void game();

//对数组初始化
void resetarr(char arr [ROW][COL]);


//打印棋盘
void display(char arr[ROW][COL],int row, int col);


//玩家下棋
void player(char arr[ROW][COL]);


//电脑下棋
void computer(char arr[ROW][COL]);

//判断输赢
int judge(char arr[ROW][COL]);