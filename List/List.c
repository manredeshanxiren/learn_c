#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->data = x;
	node->next = node->prev = NULL;
	return node;
}

//初始化双向链表
LTNode* InitList()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//双向链表的尾插
void  LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->prev;

	//tail->next = newnode;
	//newnode->prev = tail;
	//phead->prev = newnode;
	//newnode->next = phead;
	LTInsert(phead, x);
}

//双向链表的尾部删除
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	//LTNode* tail = phead->prev;
	//LTNode* tailprev = tail->prev;

	//tailprev->next = phead;
	//phead->prev = tailprev;
	//free(tail); 
	LTErase(phead->prev);
}

//双向链表的头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	//LTNode* newnode = BuyListNode(x);
	//newnode->next = phead->next;
	//phead->next->prev = newnode;

	//phead->next = newnode;
	//newnode->prev = phead;
	LTInsert(phead->next, x);
}

//双向链表的打印
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//双向连边头部删除数据
void LTPopFront(LTNode* phead)
{
	assert(phead);
	//assert(phead->next != NULL);
	//LTNode* first = phead->next;
	//LTNode* second = first->next;

	//free(first);
	//phead->next = second;
	//second->prev = phead;
	LTErase(phead->next);
}

//双向链表中寻找数据
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在双向链表的任意位置插入和删除数据
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* pre = pos->prev;

	pre->next = newnode;
	newnode->prev = pre;
	newnode->next = pos;
	pos->prev = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* pre = pos->prev;
	LTNode* next = pos->next;
	free(pos);
	pre->next = next;
	next->prev = pre;
}

//双向链表的判空
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next != phead;
}

//双向链表大小的计算
size_t LTSize(LTNode* phead)
{
	assert(phead);
	size_t x = 0;
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		x++;
		cur = cur->next;
	}
	return x;
}

//双向链表的销毁
void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}