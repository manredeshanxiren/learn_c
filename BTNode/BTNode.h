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

//����ڵ�
BTNode* BuyNode(BTDataType x);

//ǰ��ݹ�
void PrevOrder(BTNode* root);

//����ݹ�
void InOrder(BTNode* root);

//����ݹ�
void PostOrder(BTNode* root);

//������ĸ���
int TreeSize(BTNode* root);

//����Ҷ�ӽڵ�
int TreeLeafSize(BTNode* root);

//�����ĸ߶�
int TreeHeight(BTNode* root);

//�������ĵ�k���м����ڵ�
int TreeKLeveSize(BTNode* root, int k);

//ǰ��ݹ齨��������
BTNode* TreeCreat(BTNode* root);