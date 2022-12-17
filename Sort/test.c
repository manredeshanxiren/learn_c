#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"stack.h"

//—°‘Ò≈≈–Ú≤‚ ‘
void SelectSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("—°‘Ò≈≈–Ú:\n");
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//≤Â»Î≈≈–Ú≤‚ ‘
void InsertSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("≤Â»Î≈≈–Ú:\n");
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//œ£∂˚≈≈–Ú≤‚ ‘
void ShellSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("œ£∂˚≈≈–Ú:\n");
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");

}

//∂—≈≈–Ú≤‚ ‘
void HeapSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("∂—≈≈–Ú:\n");
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//√∞≈›≈≈–Ú≤‚ ‘
void BubbleSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("√∞≈›≈≈–Ú:\n");
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//øÏÀŸ≈≈–Ú≤‚ ‘
void QuickSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };

	printf("øÏÀŸ≈≈–Ú:\n");
	QuickSort(a, 0,sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//∑«µ›πÈøÏÀŸ≈≈–Ú≤‚ ‘
void QuickSortSTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	printf("∑«µ›πÈøÏÀŸ≈≈–Ú:\n");
	QuickSortS(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//πÈ≤¢≈≈–Ú≤‚ ‘
void MergeSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	printf("πÈ≤¢≈≈–Ú:\n");
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}

//πÈ≤¢≈≈–Ú∑«µ›πÈ∞Ê≤‚ ‘
void MergeSortSTest()
{
	int a[] = {9,8,7,6,5,4,3,2,1 };
	printf("πÈ≤¢(∑«µ›πÈ)≈≈–Ú:\n");
	MergeSortS(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	printf("\n");
}
//º∆ ˝≈≈–Ú≤‚ ‘
void CountSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	printf("º∆ ˝≈≈–Ú:\n");
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