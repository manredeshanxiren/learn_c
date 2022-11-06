#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
typedef int SLDateType;

typedef struct SListNode
{
	SLDateType data;
	struct SListNode* next;
}SLNode; 

//打印链表数据
void SLprint(SLNode* plist);

//头插尾插
void SLPushBack(SLNode** pplist, SLDateType x);
void SLPushFront(SLNode** pplist, SLDateType x);

//头删尾删
void SLPopBack(SLNode** pplist);
void SLPopFront(SLNode** pplist);

//单链表查找
SLNode* SLFind(SLNode* plist, SLDateType x);

//在对应位置后插入
void SListInsertAfter(SLNode* pos, SLDateType x);

//在对应位置前插入
void SListInsertAfter(SLNode** pphead, SLNode* pos, SLDateType x);

//在对应后位置删除
void SListEraseAfter(SLNode* pos);

//删除对应的位置
void SListErase(SLNode** pphead, SLNode* pos);