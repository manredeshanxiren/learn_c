#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef struct josephusdata
{
	int k;
	bool x;//ture 表示在队伍内
}jsdata;

typedef struct josephus
{
	jsdata data;
	struct josephus* next;
}js;


//创建循环链表
void CreatList(js* head, int n);

//打印链表
void PrintList(js* head);

//出列
int* DequeueList(js* head, int n, int m);

//让所有人回到队列
void ResetList(js* head);
