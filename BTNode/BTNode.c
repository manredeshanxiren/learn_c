#define _CRT_SECURE_NO_WARNINGS 1
#include"BTNode.h"

//队列的初始化
void InitQueue(Queue* pq)
{
	pq->head = NULL;
	pq->head = NULL;
	pq->size = 0;
}

//队列的大小
int QueueSize(Queue* pq)
{
	return pq->size;
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

//出队列
void QueuePop(Queue* pq, BTNode** temp)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	//剩余一个节点的情况
	if (pq->head->next == NULL)
	{
		*temp = pq->head->data;
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* del = pq->head;
		pq->head = pq->head->next;
		*temp = del->data;
		free(del);
	}
	pq->size--;
}

//返回队列的首元素
QdataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}

//申请节点
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

//前序递归
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

//中序递归
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

//后序递归
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

//计算结点的个数
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1;
}

//计算叶子节点
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

//计算树的第k层有几个节点
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

//创建树
BTNode* Creat(BTNode* root)
{
		char ch;
		ch = getchar();
		if (ch == '#') {
			return NULL;
		}
		else {
			root = (BTNode*)malloc(sizeof(BTNode));
			root->data = ch;
			root->left = Creat(root->left);
			root->right = Creat(root->right);
		}
		return root;
}

//在树中查找
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (!root)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
	{
		return ret1;
	}
	BTNode* ret2 = TreeFind(root->left, x);
	if (ret2)
	{
		return ret2;
	}
	return NULL;
}

////二叉树的层序遍历
//void LevelOrder(BTNode* root)
//{
//	Queue q;
//	BTNode* temp;
//	InitQueue(&q);
//	if(root)
//	QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		QueuePop(&q, &temp);
//		printf("%c ", temp->data);
//		if (temp->left)
//			QueuePush(&q, temp->left);
//		if (temp->right)
//			QueuePush(&q, temp->right);
//	}
//	QueueDestroy(&q);
//}


//二叉树的层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	BTNode* temp;
	InitQueue(&q);
	if (root)
		QueuePush(&q, root);
	int levelsize = QueueSize(&q);
	while (!QueueEmpty(&q))
	{
		//一层一层出
		while (levelsize--)
		{
			QueuePop(&q, &temp);
			printf("%c ", temp->data);
			if (temp->left)
				QueuePush(&q, temp->left);
			if (temp->right)
				QueuePush(&q, temp->right);
		}
		printf("\n");
		levelsize = QueueSize(&q);
	}
	QueueDestroy(&q);
}

//判断二叉树是否是完全二叉树
bool TreeComplete(BTNode* root)
{
	Queue q;
	BTNode* temp;
	InitQueue(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		QueuePop(&q, &temp);
		if (!temp)
		{
			break;
		}
		else
		{
			QueuePush(&q,temp->left);
			QueuePush(&q, temp->right);
		}
	}
	while (!QueueEmpty(&q))
	{
		QueuePop(&q, &temp);
		if (temp)
		{
			return false;
		}
	}
	return true;
	QueueDestroy(&q);
}

//二叉树的销毁
//此函数调用结束后要对root置空
void TreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}
