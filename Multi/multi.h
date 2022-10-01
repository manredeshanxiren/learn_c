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

//������ʽ����
mu* InputFormula(int i);

//��ӡ���ʽ
void PrintFormula(mu* pa);

//���������ʽ���
mu* SubFormula(mu* pa, mu* pb);

//���������ʽ���
mu* SubtractFormula(mu* pa, mu* pb);

//���������ʽ���
mu* MultiFormula(mu* pa, mu* pb);

//�������ʽ��ֵ
long long  ValueFormula(mu* pa);

//�������ʽ�ĵ���
mu* DerivatFormula(mu* pa);