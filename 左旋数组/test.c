#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_STRING 100
#include<stdio.h>
#include<string.h>
//��������
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
void LeftHandedArray(char* arr, int k, int arrSize)
{
	//˼·��Դ��leetcode
	//��������
	//���ڽ���ǰ�ַ������������൱�ڽ���������ַ�������������
	char brr[MAX_STRING] = { 0 };
	for (int i = 0; i < arrSize; i++)
	{
		brr[i] = arr[(i + k) % arrSize];//���Կɵô��д���˼·
	}
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = brr[i];
	}
}
#include<stdio.h>
int main()
{
	char arr[] = { "ABCD" };
	int k = 0;
	int arrSize = strlen(arr);
	scanf("%d", &k);
	LeftHandedArray(arr, k, arrSize);
	printf("%s", arr);
}