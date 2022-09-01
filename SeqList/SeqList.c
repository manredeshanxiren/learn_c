#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//˳���ĳ�ʼ��
void SeqListInit(SeqList* pSeq)
{
	//����
	//���pSeqΪ��ָ������ֹ���򣬲�����ʾ��������λ��
	//assert(pSeq != NULL);
	assert(pSeq);

	pSeq->a = NULL;
	pSeq->size = pSeq->capacity = 0;
}

//˳��������
void SeqListDestroy(SeqList* pSeq)
{
	assert(pSeq);

	free(pSeq->a);
	pSeq->a = NULL;
	pSeq->size = pSeq->capacity = 0;
}
//��ӡ˳����е�����
void SeqListPrint(SeqList* pSeq)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->a[i]);
	}
	printf("\n");
}
//���˳���Ĵ�С�Ƿ���
void CheckSeqList(SeqList* pSeq)
{
	//����ռ䲻������Ҫ����
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
//β��
void SeqListPushBack(SeqList* pSeq, SeqType x)
{
	SeqListInsert(pSeq, pSeq->size, x);
	//assert(pSeq);

	////����ռ䲻������Ҫ����
	//CheckSeqList(pSeq);
	//pSeq->a[pSeq->size] = x;
	//pSeq->size++;
}
//ͷ��
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

//β��ɾ��
void SeqListPopBack(SeqList* pSeq)
{
	SeqListErase(pSeq, pSeq->size);
	//assert(pSeq);
	//assert(pSeq->size > 0);//�ж�size�Ƿ������
	//pSeq->size--;
}

//ͷ��ɾ��
void SeqListPopFront(SeqList* pSeq)
{
	SeqListErase(pSeq, 0);
	//assert(pSeq);
	//assert(pSeq->size > 0);//�ж�size�Ƿ������
	//for (int i = 1; i < pSeq->size; i++)
	//{
	//	pSeq->a[i - 1] = pSeq->a[i];
	//}
	//pSeq->size--;
}

//��˳���Ѱ��Ԫ��
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

//��˳�������λ�ò���
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

//��˳�������λ��ɾ��
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

//��˳����޸�
void SeqListModify(SeqList* pSeq, int pos, SeqType x)
{
	assert(pos >= 0 && pos < pSeq->size);
	pSeq->a[pos] = x;
}