#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"

void SLTest1(SLNode* plist)
{
	SLPushFront(&plist, 9);
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLPushBack(&plist, 5);
	SLPushFront(&plist, 10);
	SLprint(plist);
	SLNode* ret = SLFind(plist, 4);
	SListInsertAfter(ret, 100);
	SLprint(plist); 
	SListEraseAfter(ret);
	SLprint(plist);

}
int main()
{
	SLNode* plist = NULL;
	SLTest1(plist);








	return 0;
}