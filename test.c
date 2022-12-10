#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


//—°‘Ò≈≈–Ú≤‚ ‘
void SelectSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("—°‘Ò≈≈–Ú:\n");
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//≤Â»Î≈≈–Ú≤‚ ‘
void InsertSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("≤Â»Î≈≈–Ú:\n");
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//œ£∂˚≈≈–Ú≤‚ ‘
void ShellSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("œ£∂˚≈≈–Ú:\n");
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//∂—≈≈–Ú≤‚ ‘
void HeapSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("∂—≈≈–Ú:\n");
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//√∞≈›≈≈–Ú≤‚ ‘
void BubbleSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("√∞≈›≈≈–Ú:\n");
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//øÏÀŸ≈≈–Ú≤‚ ‘
void QuickSortTest()
{
	int a[] = { 2,5,4,7,8,2,4,7,9,10,24 };
	printf("øÏÀŸ≈≈–Ú:\n");
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