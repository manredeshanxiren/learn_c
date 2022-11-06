#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//初始化双向链表
LTNode* InitList();

//获取新的节点
LTNode* BuyListNode(LTDataType x);

//双向链表的尾插
void  LTPushBack(LTNode* phead, LTDataType x);

//双向链表的尾部删除
void LTPopBack(LTNode* phead);


//双向链表的头插
void LTPushFront(LTNode* phead, LTDataType x);

//双向链表的打印
void LTPrint(LTNode* phead);

//双向连边头部删除数据
void LTPopFront(LTNode* phead);

//双向链表中寻找数据
LTNode* LTFind(LTNode* phead, LTDataType x);

//在双向链表的任意位置插入和删除数据
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);

//双向链表的判空
bool LTEmpty(LTNode* phead);

//双向链表大小的计算
size_t LTSize(LTNode* phead);

//双向链表的销毁
void LTDestroy(LTNode* phead);