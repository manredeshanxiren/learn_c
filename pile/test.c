#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
void test1()
{
	HP  heap;
	HeapInit(&heap);
	int arr[] = { 1, 3, 21 ,45, 56, 78, 65, 23, 55 };
	for (int i = 0; i < 9; i++)
	{
		HeapPush(&heap, arr[heap.size]);
	}
	HeapPrint(&heap);
}
int main()
{
	test1();
	int n;




	return 0;
}