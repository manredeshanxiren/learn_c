#define _CRT_SECURE_NO_WARNINGS 1
#include"BTNode.h"

//���еĳ�ʼ��
void InitQueue(Queue* pq)
{
	pq->head = NULL;
	pq->head = NULL;
	pq->size = 0;
}

//���еĴ�С
int QueueSize(Queue* pq)
{
	return pq->size;
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
void QueuePop(Queue* pq, BTNode** temp)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	//ʣ��һ���ڵ�����
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

//���ض��е���Ԫ��
QdataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}

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

//������
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

//�����в���
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

////�������Ĳ������
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


//�������Ĳ������
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
		//һ��һ���
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

//�ж϶������Ƿ�����ȫ������
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

//������������
//�˺������ý�����Ҫ��root�ÿ�
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
