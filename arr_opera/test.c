#define _CRT_SECURE_NO_WARNINGS 1
//����һ���������飬��ɶ�����Ĳ���
//
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�
//Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
#include<stdio.h>
void init(int* a, int n)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		a[i] = 0;
	}
}
void print(int* a, int n)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void reverse(int* arr, int n)
{
	int i = 0;
	while (i < n / 2)
	{
		int a;
		a = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = a;
		i++;
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	reverse(arr, 10);
	print(arr, 10);
	init(arr, 10);
	print(arr, 10);
	return 0;
}