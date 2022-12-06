#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

typedef BTNode* QdataType;

typedef struct QueueNode
{
	QdataType data;
	struct QueueNode* next;

}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	size_t size;
}Queue;

//���еĳ�ʼ��
void InitQueue(Queue* pq);

//���еĴ�С
int QueueSize(Queue* pq);

//���е�����
void QueueDestroy(Queue* pq);

//�����
void QueuePush(Queue* pq, QdataType x);

//������
void QueuePop(Queue* pq);

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//����ڵ�
BTNode* BuyNode(BTDataType x);

//ǰ��ݹ�
void PrevOrder(BTNode* root);

//����ݹ�
void InOrder(BTNode* root);

//����ݹ�
void PostOrder(BTNode* root);

//�������
void LevelOrder(BTNode* root);

//�������Ĳ������
void LevelOrder(BTNode* root);

//������ĸ���
int TreeSize(BTNode* root);

//����Ҷ�ӽڵ�
int TreeLeafSize(BTNode* root);

//�����ĸ߶�
int TreeHeight(BTNode* root);

//�������ĵ�k���м����ڵ�
int TreeKLeveSize(BTNode* root, int k);

//������
BTNode* Creat(BTNode* root);

//�����в���
BTNode* TreeFind(BTNode* root, BTDataType x);

//���ض��е���Ԫ��
QdataType QueueFront(Queue* pq);

//�ж϶������Ƿ�����ȫ������
bool TreeComplete(BTNode* root);

//������������
//�˺������ý�����Ҫ��root�ÿ�
void TreeDestroy(BTNode* root);
