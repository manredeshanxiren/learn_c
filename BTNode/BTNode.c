#define _CRT_SECURE_NO_WARNINGS 1
#include"BTNode.h"
//����ڵ�
BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}

	node->data = x;
	node->left = node->right = NULL;
	return node;
}

//ǰ��ݹ�
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//����ݹ�
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//����ݹ�
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

//������ĸ���
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1;
}


//����Ҷ�ӽڵ�
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if(root->left == NULL && root->right == NULL)  
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}


//�����ĸ߶�
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int LeftHeight = TreeHeight(root->left);
	int RightHeight = TreeHeight(root->right);
	return LeftHeight > RightHeight ?
		LeftHeight + 1 : RightHeight + 1;
}

//�������ĵ�k���м����ڵ�
int TreeKLeveSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeKLeveSize(root->left, k - 1) +
		TreeKLeveSize(root->right, k - 1);
}


//ǰ��ݹ齨��������
BTNode* TreeCreat(BTNode* root)
{
	char ch;
	ch = getchar();
	if (ch == '#')
	{
		return NULL;
	}
	else
	{
		root = (BTNode*)malloc(sizeof(BTNode));
		root->data = ch;
		root->left = TreeCreat(root->left);
		root->left = TreeCreat(root->left);
	}
	return root;
}