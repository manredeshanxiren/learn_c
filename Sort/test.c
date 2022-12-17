#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"stack.h"

//ѡ���������
void SelectSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("ѡ������:\n");
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//�����������
void InsertSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("��������:\n");
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//ϣ���������
void ShellSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("ϣ������:\n");
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//���������
void HeapSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("������:\n");
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//ð���������
void BubbleSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("ð������:\n");
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//�����������
void QuickSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("��������:\n");
	QuickSort(a, 0,sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//�ǵݹ�����������
void QuickSortSTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	printf("�ǵݹ��������:\n");
	QuickSortS(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//�鲢�������
void MergeSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	printf("�鲢����:\n");
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//�鲢����ǵݹ�����
void MergeSortSTest()
{
	int a[] = {9,8,7,6,5,4,3,2,1 };
	printf("�鲢(�ǵݹ�)����:\n");
	MergeSortS(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}
//�����������
void CountSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	printf("��������:\n");
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

int main()
{
	HeapSortTest();
	ShellSortTest();
	InsertSortTest();
	SelectSortTest();
	BubbleSortTest();
	QuickSortTest();
	QuickSortSTest();
	MergeSortTest();
	MergeSortSTest();
	CountSortTest();
}