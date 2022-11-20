#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;

}HP;

//堆的初始化
void HeapInit(HP* php);

//堆的销毁
void HeapDestroy(HP* php);

//堆的插入
void HeapPush(HP* php, HPDataType x);

//向上调整
void AdjustUp(HPDataType* a, int child);

//堆的打印
void  HeapPrint(HP* php);

//堆的删除
void HeapDown(HP* php);

//向下调整
void AdjustDown(HPDataType* a, int size, int parent);

//取堆顶的数据
void HeapTop(HP* php);

//堆是否为空
bool HeapEmpty(HP* php);

//创建堆的函数
void HeapCreate(HP* php, HPDataType* a, int n);