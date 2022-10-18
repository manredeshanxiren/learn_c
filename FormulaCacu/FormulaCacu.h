#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

typedef double cacutype;

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<ctype.h>

typedef double STDataType;
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

//������ʽ��ֵ
cacutype Calu();

//���������ȼ��Ƚ�
char compare(char theta1, char theta2);
