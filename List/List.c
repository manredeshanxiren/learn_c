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

//��ʼ��˫������
LTNode* InitList()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//˫�������β��
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

//˫�������β��ɾ��
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

//˫�������ͷ��
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

//˫������Ĵ�ӡ
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

//˫������ͷ��ɾ������
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

//˫��������Ѱ������
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

//��˫�����������λ�ò����ɾ������
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

//˫��������п�
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next != phead;
}

//˫�������С�ļ���
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

//˫�����������
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