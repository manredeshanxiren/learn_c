#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;

}HP;

//�ѵĳ�ʼ��
void HeapInit(HP* php);

//�ѵ�����
void HeapDestroy(HP* php);

//�ѵĲ���
void HeapPush(HP* php, HPDataType x);

//���ϵ���
void AdjustUp(HPDataType* a, int child);

//�ѵĴ�ӡ
void  HeapPrint(HP* php);

//�ѵ�ɾ��
void HeapDown(HP* php);

//���µ���
void AdjustDown(HPDataType* a, int size, int parent);

//ȡ�Ѷ�������
HPDataType HeapTop(HP* php);

//���Ƿ�Ϊ��
bool HeapEmpty(HP* php);

//�����ѵĺ���
void HeapCreate(HP* php, HPDataType* a, int n);

//��������
void Swap(HPDataType* a, HPDataType* b);

//������
void HeapSort(HPDataType* a, size_t n);