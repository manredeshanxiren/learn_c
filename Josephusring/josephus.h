#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef struct josephusdata
{
	int k;
	bool x;//ture ��ʾ�ڶ�����
}jsdata;

typedef struct josephus
{
	jsdata data;
	struct josephus* next;
}js;


//����ѭ������
void CreatList(js* head, int n);

//��ӡ����
void PrintList(js* head);

//����
int* DequeueList(js* head, int n, int m);

//�������˻ص�����
void ResetList(js* head);
