#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"

//��ӡ��������
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
//����ڵ��ڴ�ռ�
SLNode* BuySLNode(SLDateType x)
{
	SLNode* New = (SLNode*)malloc(sizeof(SLNode));
	New->data = x;
	New->next = NULL;
	return New;
}


//β��
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

//ͷ��
void SLPushFront(SLNode** pplist, SLDateType x)
{
	SLNode* New = BuySLNode(x);
	New->next = *pplist;
	*pplist = New;
}

//βɾ
void SLPopBack(SLNode** pplist)
{
	//1.�޽ڵ�
	//2.һ���ڵ�
	//3.�����ڵ�
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

//ͷɾ
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

//���������
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

//�ڶ�Ӧ��λ�ò���
void SListInsertAfter(SLNode* pos, SLDateType x)
{
	assert(pos);
	SLNode* New = BuySLNode(x);
	New->next = pos->next;
	pos->next = New;
}

//�ڶ�Ӧλ��ǰ����
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

//�ڶ�Ӧ��λ��ɾ��
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
		//ɾ������
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

//ɾ����Ӧ��λ��
void SListErase(SLNode** pphead, SLNode* pos);

//ɾ����Ӧ��λ��
void SListErase(SLNode** pphead, SLNode* pos)
{
	assert(pos);
	if (pos == *pphead)
	{
		//ֱ��ͷɾ
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