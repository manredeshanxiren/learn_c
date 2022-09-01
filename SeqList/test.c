#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
TestSeqList()
{
	SeqList s = {NULL, 0, 0};
	SeqListInit(&s);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 6);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 10);
	SeqListPrint(&s);
	SeqListErase(&s, 2);
	SeqListPrint(&s);
	SeqListModify(&s, 0, 100);
	SeqListPrint(&s);



	SeqListDestroy(&s);
}
int main()
{
	TestSeqList();

	return 0;
}