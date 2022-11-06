#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"

//打印链表数据
void SLprint(SLNode* plist)
{
	SLNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NLLL\n");
}
//申请节点内存空间
SLNode* BuySLNode(SLDateType x)
{
	SLNode* New = (SLNode*)malloc(sizeof(SLNode));
	New->data = x;
	New->next = NULL;
	return New;
}


//尾插
void SLPushBack(SLNode** pplist, SLDateType x)
{
	if (*pplist == NULL)
	{
		*pplist = BuySLNode(x);
	}
	else
	{
		SLNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = BuySLNode(x);
	}
}

//头插
void SLPushFront(SLNode** pplist, SLDateType x)
{
	SLNode* New = BuySLNode(x);
	New->next = *pplist;
	*pplist = New;
}

//尾删
void SLPopBack(SLNode** pplist)
{
	//1.无节点
	//2.一个节点
	//3.三个节点
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	else
	{
		SLNode* pre = NULL;
		SLNode* tail = *pplist;
		while (tail->next != NULL)
		{
			pre = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		pre->next = NULL;
	}
}

//头删
void SLPopFront(SLNode** pplist)
{
	if ((*pplist) == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	else
	{
		SLNode* Temp = *pplist;
		*pplist = (*pplist)->next;
		free(Temp);
		Temp = NULL;
	}
}

//单链表查找
SLNode* SLFind(SLNode* plist, SLDateType x)
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}
	return NULL;
}

//在对应后位置插入
void SListInsertAfter(SLNode* pos, SLDateType x)
{
	assert(pos);
	SLNode* New = BuySLNode(x);
	New->next = pos->next;
	pos->next = New;
}

//在对应位置前插入
void SListInsertAfter(SLNode** pphead, SLNode* pos, SLDateType x)
{
	assert(pos);
	if (pos == *pphead)
	{
		SLPushFront(pphead, x);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLNode* new = BuySLNode(x);
		prev->next = new;
		new->next = pos;
	}
}

//在对应后位置删除
void SListEraseAfter(SLNode* pos)
{
	SLNode* cur = pos;
	cur = pos->next;
	if (pos->next == NULL)
	{
		return;
	}
	else if (cur->next == NULL)
	{
		//删除即可
		cur = cur->next;
		free(cur);
		cur = NULL;
	}
	else
	{
		SLNode* temp = pos->next;
		pos->next = temp->next;
		free(temp);
		temp = NULL;
	}
}

//删除对应的位置
void SListErase(SLNode** pphead, SLNode* pos);

//删除对应的位置
void SListErase(SLNode** pphead, SLNode* pos)
{
	assert(pos);
	if (pos == *pphead)
	{
		//直接头删
		SLPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}