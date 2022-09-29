#define _CRT_SECURE_NO_WARNINGS 1
#include"josephus.h"

//�����½ڵ�
static js* GetNewNode(int i)
{
	js* Pnew = (js*)malloc(sizeof(js));
	if (Pnew == NULL)
	{
		perror(errno);
	}
	Pnew->data.k = i;
	return Pnew;
}

//����ѭ������
void CreatList(js* head, int n)
{
	assert(head);
	js* p = head;
	for (int i = 1; i <= n; i++)
	{
		js* Pnew = GetNewNode(i);
		p->next = Pnew;
		Pnew->data.x = true;
		p = p->next;
	}
	p->next = head->next;
}

//��ӡ����
void PrintList(js* head)
{
	assert(head);
	if (head->next != NULL)
	{
		js* p = head->next;
		js* q = p;
		do {
			printf("%d ", p->data.k);
			p = p->next;
		} while (p != q);
	}
	else
	return;
}

//����
int* DequeueList(js* head, int n, int m)
{
	js* p = head->next;
	int z = n;
	int y = 1;
	int* brr = (int*)malloc(sizeof(int) * n);
	while (z)
	{
		if (y % m == 0 && p->data.x == true)
		{
			brr[n - z] = p->data.k;
			//printf("%d ", p->data.k);
			p->data.x = false;
			z--;
		}
		p = p->next;
		if(p->data.x == true)
		y++;
	}
	//printf("\n");
	return brr;
}


//�������˻ص�����
void ResetList(js* head)
{
	assert(head);
	js* p = head->next;
	js* q = p;
	do {
		p->data.x = true;
		p = p->next;
	} while (p != q);
	return;
}