#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

////������̬��˳���
// //#define N 100
//struct SeqList
//{
//	int a[N];
//	int size;
//};

typedef int SeqType;
typedef struct SeqList
{
	SeqType* a;
	int size;		//��Ч���ݵĸ���
	int capacity;   //������С
}SeqList;


//˳���ĳ�ʼ��
void SeqListInit(SeqList* pSeq);

//˳��������
void SeqListDestroy(SeqList* pSeq);


//��ӡ˳����е�����
void SeqListPrint(SeqList* pSeq);

//���˳���Ĵ�С�Ƿ���
void CheckSeqList(SeqList* pSeq);
//˳������ɾ��ĵĽӿ�
//
void SeqListPushBack(SeqList* pSeq, SeqType x);
void SeqListPushFront(SeqList* pSeq, SeqType x);
void SeqListPopBack(SeqList* pSeq);
void SeqListPopFront(SeqList* pSeq);
//��˳���Ѱ��Ԫ��
int SeqListFind(SeqList* pSeq, SeqType x);

//��˳�������λ�ò���
void SeqListInsert(SeqList* pSeq,int pos ,SeqType x);

//��˳�������λ��ɾ��
void SeqListErase(SeqList* pSeq, int pos);

//��˳����޸�
void SeqListModify(SeqList* pSeq, int pos, SeqType x);