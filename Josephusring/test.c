#define _CRT_SECURE_NO_WARNINGS 1
#include"josephus.h"
int main()
{
	int n;
	int k;
	int arr[10];
	
	printf("������n��k:>");
	scanf("%d%d", &n, &k);
	if (k > 10 && k <= n)
		exit;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &arr[i]);
	}
	js* head = (js*)malloc(sizeof(js));
	head->next = NULL;
	//����ѭ������
	CreatList(head, n);
	//��ӡ����
	//PrintList(head);
	//����
	for (int i = 1; i <= n; i++)
	{
		bool Judge = true;
		int* brr = DequeueList(head, n, i);
		for (int j = 0; j < k; j++)
		{
			if (arr[j] != brr[n - k + j])
			{
				Judge = false; 
					break;
			}
		}
		if (Judge == true)
		{
			printf("%d", i);
			//break;
		}
		ResetList(head);
	}
	return 0;
}