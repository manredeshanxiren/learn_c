#define _CRT_SECURE_NO_WARNINGS 1
#include"BTNode.h"


int main()
{
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root = Creat(root); //��չ�������н����� 
	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	LevelOrder(root);
	printf("\n%d", TreeComplete(root));
	TreeDestroy(root);
	return 0;
}

