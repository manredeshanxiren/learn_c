#pragma once
#include<stdio.h>
#include<stdlib.h>



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

//三数选择
int GetMidIndex(int* a, int begin, int end);

//hoare法
int PartSort1(int* a, int begin, int end);

//挖坑法
int PartSort2(int* a, int begin, int end);

//前后指针法
int PartSort3(int* a, int begin, int end);

//快速排序（非递归）
void QuickSortS(int* a, int begin, int end);

//归并排序
void MergeSort(int* a, int size);

//归并排序非递归版
void MergeSortS(int* a, int size);

//基数排序
void RadixSort(int* arr, int size);

//申请空间
int* GetMemory(size_t size);

//计数排序
void CountSort(int* arr, int size);