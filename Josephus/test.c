#define _CRT_SECURE_NO_WARNINGS 1
#include"josephus.h"

int main()
{
	js* head = (js*)malloc(sizeof(js));

	int n;//PeopleNumber
	int m;//limit
	scanf("%d%d", &n, &m);
	//�����ڵ�
	CreatJs(head, n);
	//����
	DequeueJs(head ,m, n);
	return 0;

}