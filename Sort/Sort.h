#pragma once
#include<stdio.h>



//打印数组
void PrintArray(int* a, int size);

//插入排序
void InsertSort(int* a, int size);

//希尔排序
void ShellSort(int* a, int size);

//选择排序
void SelectSort(int* a, int size);

//向下调整   O(N)
void AdjustDown(int* a, int size, int parent);

//堆排序
void HeapSort(int* a, int size);

//冒泡排序
void BubbleSort(int* a, int size);

//快速排序
void QuickSort(int* a, int begin, int end);