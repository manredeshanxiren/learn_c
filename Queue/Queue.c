#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//队列的初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

//队列的销毁
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

//入队列
void QueuePush(Queue* pq, QdataType x)
{
	assert(pq);
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	NewNode->next = NULL;
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
}

//出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	//解决队列删空的情况
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}

//返回队列的首元素
QdataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

//返回队列的尾部元素
QdataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

//队列的大小
int QueueSize(Queue* pq) 
{
	assert(pq);
	int n = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}

//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
