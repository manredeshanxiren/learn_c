#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<ctype.h>

typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//ջ�ĳ�ʼ��
void StackInit(ST* ps);

//ջ������
void StackDestroy(ST* ps);

//��ջ
void StackPush(ST* ps, STDataType x);

//��ջ
void StackPop(ST* ps);

//�õ�ջ��������
STDataType StackTop(ST* ps);

//ջ�Ĵ�С
int StackSize(ST* ps);

//ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);