#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//���е�����
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

//�����
void QueuePush(Queue* pq, QdataType x)
{
	assert(pq);
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	NewNode->next = NULL;
	NewNode->data = x;
	if (pq->head == NULL)
	{
		pq->head = NewNode;
		pq->tail = NewNode;
	}
	else
	{
		pq->tail->next = NewNode;
		pq->tail = NewNode;
	}
	pq->size++;
}

//������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	//ʣ��һ���ڵ�����
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
	}
	pq->size--;
}

//���ض��е���Ԫ��
QdataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

//���ض��е�β��Ԫ��
QdataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

//���еĴ�С
int QueueSize(Queue* pq) 
{
	//assert(pq);
	//int n = 0;
	//QueueNode* cur = pq->head;
	//while (cur)
	//{
	//	n++;
	//	cur = cur->next;
	//}
	//return n;
	return pq->size;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}
