#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef QdataType;

typedef struct QueueNode
{
	QdataType data;
	struct QueueNode* next;

}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;


//���еĳ�ʼ��
void QueueInit(Queue* pq);

//���е�����
void QueueDestroy(Queue* pq);

//�����
void QueuePush(Queue* pq, QdataType x);

//������
void QueuePop(Queue* pq);

//���ض��е���Ԫ��
QdataType QueueFront(Queue* pq);

//���ض��е�β��Ԫ��
QdataType QueueBack(Queue* pq);

//���еĴ�С
int QueueSize(Queue* pq);

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);