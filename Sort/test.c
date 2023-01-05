#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"stack.h"

// ≤‚ ‘≈≈–Úµƒ–‘ƒ‹∂‘±»
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6); 
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

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
//ª˘ ˝≈≈–Ú≤‚ ‘
void RadixSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	printf("ª˘ ˝≈≈–Ú:\n");
	RadixSort(a, sizeof(a) / sizeof(int));
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
	RadixSortTest();
	CountSortTest();
	//TestOP();
}