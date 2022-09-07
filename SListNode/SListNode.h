#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
typedef int SLDateType;

typedef struct SListNode
{
	SLDateType data;
	struct SListNode* next;
}SLNode; 

//��ӡ��������
void SLprint(SLNode* plist);

//ͷ��β��
void SLPushBack(SLNode** pplist, SLDateType x);
void SLPushFront(SLNode** pplist, SLDateType x);

//ͷɾβɾ
void SLPopBack(SLNode** pplist);
void SLPopFront(SLNode** pplist);

//����������
SLNode* SLFind(SLNode* plist, SLDateType x);

//�ڶ�Ӧ��λ�ò���
void SListInsertAfter(SLNode* pos, SLDateType x);

//�ڶ�Ӧ��λ��ɾ��
void SListEraseAfter(SLNode* pos);