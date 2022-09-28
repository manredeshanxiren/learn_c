#define _CRT_SECURE_NO_WARNINGS 1
#include"josephus.h"

int main()
{
	js* head = (js*)malloc(sizeof(js));

	int n;//PeopleNumber
	int m;//limit
	scanf("%d%d", &n, &m);
	//创建节点
	CreatJs(head, n);
	//出列
	DequeueJs(head ,m, n);
	return 0;

}