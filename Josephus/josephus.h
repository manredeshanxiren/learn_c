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
//�����ڵ㺯��
void CreatJs(js * head, int n);

//����
void DequeueJs(js* head,int m, int n);
