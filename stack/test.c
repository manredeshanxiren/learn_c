#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void Teststack()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}



	StackDestroy(&st);

}


int main()
{

	Teststack();



	return 0;
}