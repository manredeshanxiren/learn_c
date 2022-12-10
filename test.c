#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


//ѡ���������
void SelectSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("ѡ������:\n");
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//�����������
void InsertSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("��������:\n");
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//ϣ���������
void ShellSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("ϣ������:\n");
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//���������
void HeapSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("������:\n");
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//ð���������
void BubbleSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("ð������:\n");
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//�����������
void QuickSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("��������:\n");
	QuickSort(a, 0,sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

int main()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	HeapSortTest();
	ShellSortTest();
	InsertSortTest();
	SelectSortTest();
	BubbleSortTest();
	QuickSortTest();
}