#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>
#include<math.h>

typedef struct Multidata
{
	int coe;
	int exp;
}mudata;

typedef struct Multi
{
	mudata data;
	struct Multi* next;
}mu;

//输入表达式函数
mu* InputFormula(int i);

//打印表达式
void PrintFormula(mu* pa);

//将两个表达式相加
mu* SubFormula(mu* pa, mu* pb);

//将两个表达式相减
mu* SubtractFormula(mu* pa, mu* pb);

//将两个表达式相乘
mu* MultiFormula(mu* pa, mu* pb);

//计算多项式的值
long long  ValueFormula(mu* pa);

//计算多项式的导数
mu* DerivatFormula(mu* pa);