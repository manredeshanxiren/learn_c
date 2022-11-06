#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//��ʼ��˫������
LTNode* InitList();

//��ȡ�µĽڵ�
LTNode* BuyListNode(LTDataType x);

//˫�������β��
void  LTPushBack(LTNode* phead, LTDataType x);

//˫�������β��ɾ��
void LTPopBack(LTNode* phead);


//˫�������ͷ��
void LTPushFront(LTNode* phead, LTDataType x);

//˫������Ĵ�ӡ
void LTPrint(LTNode* phead);

//˫������ͷ��ɾ������
void LTPopFront(LTNode* phead);

//˫��������Ѱ������
LTNode* LTFind(LTNode* phead, LTDataType x);

//��˫�����������λ�ò����ɾ������
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);

//˫��������п�
bool LTEmpty(LTNode* phead);

//˫�������С�ļ���
size_t LTSize(LTNode* phead);

//˫�����������
void LTDestroy(LTNode* phead);