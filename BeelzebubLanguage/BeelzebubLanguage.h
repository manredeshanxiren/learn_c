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

//栈的初始化
void StackInit(ST* ps);

//栈的销毁
void StackDestroy(ST* ps);

//入栈
void StackPush(ST* ps, STDataType x);

//出栈
void StackPop(ST* ps);

//拿到栈顶的数据
STDataType StackTop(ST* ps);

//栈的大小
int StackSize(ST* ps);

//栈是否为空
bool StackEmpty(ST* ps);