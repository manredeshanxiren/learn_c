#define _CRT_SECURE_NO_WARNINGS 1
#include"josephus.h"

//�����ڵ㺯��
void CreatJs(js* head, int n)
{
	js* p = head;
	for (int i = 1; i <= n; i++)
	{
		js* Pnew = (js*)malloc(sizeof(js));
		if (Pnew == NULL)
		{
			perror(errno);
			return;
		}
		printf("�������%d���˵�����:>", i);
		scanf("%d", &Pnew->data.ps);
		Pnew->data.k = i;
		p->next = Pnew;
		p = p->next;
	}
	p->next = head->next;
}

//����
void DequeueJs(js* head, int m, int n)
{
	js* p = head->next;
	js* q = p;
	while (n)
	{
		for (int i = 1; i < m; i++)
		{
			q = p;
			p = p->next;
		}
		printf("%d ", p->data.k);
		m = p->data.ps;
		q->next = p->next;
		free(p);
		p = q->next;
		n--;
	}
}