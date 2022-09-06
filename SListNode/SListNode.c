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
	if (plist == NULL)
	{
		return NULL;
	}
	else if (plist->next == NULL)
	{
		if (x == plist->data)
		{
			return plist;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		while (plist->next != NULL)
		{
			if (x == plist->data)
			{
				return plist;
			}
			plist = plist->next;
		}
	}
}

//�ڶ�Ӧ��λ�ò���
void SListInsertAfter(SLNode* pos, SLDateType x)
{
	SLNode* New = BuySLNode(x);
	New->next = pos->next;
	pos->next = New;
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