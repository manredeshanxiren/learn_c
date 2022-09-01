#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

////创建静态的顺序表
// //#define N 100
//struct SeqList
//{
//	int a[N];
//	int size;
//};

typedef int SeqType;
typedef struct SeqList
{
	SeqType* a;
	int size;		//有效数据的个数
	int capacity;   //容量大小
}SeqList;


//顺序表的初始化
void SeqListInit(SeqList* pSeq);

//顺序表的销毁
void SeqListDestroy(SeqList* pSeq);


//打印顺序表中的数据
void SeqListPrint(SeqList* pSeq);

//检查顺序表的大小是否够用
void CheckSeqList(SeqList* pSeq);
//顺序表的增删查改的接口
//
void SeqListPushBack(SeqList* pSeq, SeqType x);
void SeqListPushFront(SeqList* pSeq, SeqType x);
void SeqListPopBack(SeqList* pSeq);
void SeqListPopFront(SeqList* pSeq);
//在顺序表寻找元素
int SeqListFind(SeqList* pSeq, SeqType x);

//在顺序表任意位置插入
void SeqListInsert(SeqList* pSeq,int pos ,SeqType x);

//在顺序表任意位置删除
void SeqListErase(SeqList* pSeq, int pos);

//给顺序表修改
void SeqListModify(SeqList* pSeq, int pos, SeqType x);