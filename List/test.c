#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"


int main()
{
	LTNode* phead = InitList();
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);
	LTPrint(phead);
	LTPrint(phead);
	LTNode* x = LTFind(phead, 3);
	if (x)
	{
		x->data = 100;
		LTPrint(phead);
	}
	LTPopBack(phead);
	LTPrint(phead);
	printf("%d\n", LTSize(phead));
	LTDestroy(phead);
	return 0;
}