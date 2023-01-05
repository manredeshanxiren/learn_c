#pragma once
#include<stdio.h>
#include<stdlib.h>



//��ӡ����
void PrintArray(int* a, int size);

//��������
void InsertSort(int* a, int size);

//ϣ������
void ShellSort(int* a, int size);

//ѡ������
void SelectSort(int* a, int size);

//���µ���   O(N)
void AdjustDown(int* a, int size, int parent);

//������
void HeapSort(int* a, int size);

//ð������
void BubbleSort(int* a, int size);

//��������
void QuickSort(int* a, int begin, int end);

//����ѡ��
int GetMidIndex(int* a, int begin, int end);

//hoare��
int PartSort1(int* a, int begin, int end);

//�ڿӷ�
int PartSort2(int* a, int begin, int end);

//ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end);

//�������򣨷ǵݹ飩
void QuickSortS(int* a, int begin, int end);

//�鲢����
void MergeSort(int* a, int size);

//�鲢����ǵݹ��
void MergeSortS(int* a, int size);

//��������
void RadixSort(int* arr, int size);

//����ռ�
int* GetMemory(size_t size);

//��������
void CountSort(int* arr, int size);