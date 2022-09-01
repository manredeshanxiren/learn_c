#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//顺序表的初始化
void SeqListInit(SeqList* pSeq)
{
	//断言
	//如果pSeq为空指针则终止程序，并且显示程序错误的位置
	//assert(pSeq != NULL);
	assert(pSeq);

	pSeq->a = NULL;
	pSeq->size = pSeq->capacity = 0;
}

//顺序表的销毁
void SeqListDestroy(SeqList* pSeq)
{
	assert(pSeq);

	free(pSeq->a);
	pSeq->a = NULL;
	pSeq->size = pSeq->capacity = 0;
}
//打印顺序表中的数据
void SeqListPrint(SeqList* pSeq)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->a[i]);
	}
	printf("\n");
}
//检查顺序表的大小是否够用
void CheckSeqList(SeqList* pSeq)
{
	//如果空间不够则需要增容
	if (pSeq->size == pSeq->capacity)
	{
		int newcapacity = pSeq->capacity == 0 ? 4 : pSeq->capacity * 2;
		SeqList* newA = (SeqList*)realloc(pSeq->a, sizeof(SeqList) * newcapacity);
		if (newA == NULL)
		{
			printf("realloc is fail\n SeqListPushBack");
			exit(-1);
		}
		pSeq->a = newA;
		pSeq->capacity = newcapacity;
	}
}
//尾插
void SeqListPushBack(SeqList* pSeq, SeqType x)
{
	SeqListInsert(pSeq, pSeq->size, x);
	//assert(pSeq);

	////如果空间不够则需要增容
	//CheckSeqList(pSeq);
	//pSeq->a[pSeq->size] = x;
	//pSeq->size++;
}
//头插
void SeqListPushFront(SeqList* pSeq, SeqType x)
{
	SeqListInsert(pSeq, 0, x);
	//assert(pSeq);
	//CheckSeqList(pSeq);
	//int end = pSeq->size - 1;
	//while (end >= 0)
	//{
	//	pSeq->a[end + 1] = pSeq->a[end];
	//	end--;
	//}
	//pSeq->a[0] = x;
	//pSeq->size++;
}

//尾部删除
void SeqListPopBack(SeqList* pSeq)
{
	SeqListErase(pSeq, pSeq->size);
	//assert(pSeq);
	//assert(pSeq->size > 0);//判断size是否大于零
	//pSeq->size--;
}

//头部删除
void SeqListPopFront(SeqList* pSeq)
{
	SeqListErase(pSeq, 0);
	//assert(pSeq);
	//assert(pSeq->size > 0);//判断size是否大于零
	//for (int i = 1; i < pSeq->size; i++)
	//{
	//	pSeq->a[i - 1] = pSeq->a[i];
	//}
	//pSeq->size--;
}

//在顺序表寻找元素
int SeqListFind(SeqList* pSeq, SeqType x)
{
	for (int i = 0; i < pSeq->size; i++)
	{
		if (x == pSeq->a[i])
		{
			return i;
		}
	}
	return -1;
}

//在顺序表任意位置插入
void SeqListInsert(SeqList* pSeq, int pos, SeqType x)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);
	CheckSeqList(pSeq);
	for (int i =  pSeq->size; i > pos; i--)
	{
		pSeq->a[i] = pSeq->a[i - 1];
	}
	pSeq->a[pos] = x;
	pSeq->size++;
}

//在顺序表任意位置删除
void SeqListErase(SeqList* pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);
	for (int i = pos; i < pSeq->size - 1; i++)
	{
		pSeq->a[i] = pSeq->a[i + 1];
	}
	pSeq->size--;
}

//给顺序表修改
void SeqListModify(SeqList* pSeq, int pos, SeqType x)
{
	assert(pos >= 0 && pos < pSeq->size);
	pSeq->a[pos] = x;
}