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

//队列的初始化
void InitQueue(Queue* pq);

//队列的大小
int QueueSize(Queue* pq);

//队列的销毁
void QueueDestroy(Queue* pq);

//入队列
void QueuePush(Queue* pq, QdataType x);

//出队列
void QueuePop(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

//申请节点
BTNode* BuyNode(BTDataType x);

//前序递归
void PrevOrder(BTNode* root);

//中序递归
void InOrder(BTNode* root);

//后序递归
void PostOrder(BTNode* root);

//层序遍历
void LevelOrder(BTNode* root);

//二叉树的层序遍历
void LevelOrder(BTNode* root);

//计算结点的个数
int TreeSize(BTNode* root);

//计算叶子节点
int TreeLeafSize(BTNode* root);

//求树的高度
int TreeHeight(BTNode* root);

//计算树的第k层有几个节点
int TreeKLeveSize(BTNode* root, int k);

//创建树
BTNode* Creat(BTNode* root);

//在树中查找
BTNode* TreeFind(BTNode* root, BTDataType x);

//返回队列的首元素
QdataType QueueFront(Queue* pq);

//判断二叉树是否是完全二叉树
bool TreeComplete(BTNode* root);

//二叉树的销毁
//此函数调用结束后要对root置空
void TreeDestroy(BTNode* root);
