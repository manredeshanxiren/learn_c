#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp_int(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int arr[] = { 1, 1, 2, 2, 4, 4, 7, 7, 8, 3};
	//���ַ���
	//һ�������ɸѡ
	//������ϣ��
	//����һ��
	//qsort(arr,10, sizeof(int), cmp_int);
	//for (int i = 0; i < 10; i++)
	//	printf("%d ", arr[i]);
	//printf("\n");
	//for (int i = 0; i < 10; i++)
	//{
	//	if (arr[i] != arr[i + 1])
	//	{
	//		printf("%d ", arr[i]);
	//		continue;
	//	}
	//	else if (arr[i] == arr[i + 1])
	//	{
	//		i++;
	//	}
	//}

	//��������
	int hash[9];
	memset(hash, 0, 9 * sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		hash[arr[i]]++;
	}
	for (int i = 0; i < 9; i++)
	{
		if (hash[i] == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}