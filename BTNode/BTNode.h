#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//申请节点
BTNode* BuyNode(BTDataType x);

//前序递归
void PrevOrder(BTNode* root);

//中序递归
void InOrder(BTNode* root);

//后序递归
void PostOrder(BTNode* root);

//计算结点的个数
int TreeSize(BTNode* root);

//计算叶子节点
int TreeLeafSize(BTNode* root);

//求树的高度
int TreeHeight(BTNode* root);

//计算树的第k层有几个节点
int TreeKLeveSize(BTNode* root, int k);

//前序递归建立二叉树
BTNode* TreeCreat(BTNode* root);