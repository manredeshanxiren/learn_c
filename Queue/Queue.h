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


//队列的初始化
void QueueInit(Queue* pq);

//队列的销毁
void QueueDestroy(Queue* pq);

//入队列
void QueuePush(Queue* pq, QdataType x);

//出队列
void QueuePop(Queue* pq);

//返回队列的首元素
QdataType QueueFront(Queue* pq);

//返回队列的尾部元素
QdataType QueueBack(Queue* pq);

//队列的大小
int QueueSize(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);