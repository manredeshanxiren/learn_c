#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
void game();

//�������ʼ��
void resetarr(char arr [ROW][COL]);


//��ӡ����
void display(char arr[ROW][COL],int row, int col);


//�������
void player(char arr[ROW][COL]);


//��������
void computer(char arr[ROW][COL]);

//�ж���Ӯ
int judge(char arr[ROW][COL]);