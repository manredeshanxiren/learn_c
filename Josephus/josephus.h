#define _CRT_SECURE_NO_WARNINGS 1
#define N 10
#include<stdio.h>
#include<stdlib.h>

int arr1[N];
typedef struct josephusdata
{
	int k;
	int ps;
}jsdata;

typedef struct josephus
{
	jsdata data;
	struct josephus* next;
}js;
//创建节点函数
void CreatJs(js * head, int n);

//出列
void DequeueJs(js* head,int m, int n);
