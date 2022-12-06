#pragma once
#include<stdio.h>



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