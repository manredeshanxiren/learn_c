#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

//打印数组
void PrintArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
}

//交换函数
void Swap(int* a ,int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

//插入排序
void InsertSort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			//升序
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}

//希尔排序
void ShellSort(int* a, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				//升序
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end--;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}
	}
}

//选择排序
void SelectSort(int* a, int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin] , &a[mini]);
		//排除max在begin位置的情况
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

//向下调整   O(N)
void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

//堆排序
void HeapSort(int* a, int size)
{
	//升序：大堆
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}
	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//冒泡排序
void BubbleSort(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		int flag = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
				flag = 1;
			}
		}
		//如果一轮冒泡没有交换数据的话，那么就表示已经有序了
		if (flag == 0)
		{
			break;
		}
	}
}

//快速排序
void QuickSort(int* a, int begin, int end)
{
	//如果区间不存在就直接返回
	if (begin >= end)
	{
		return;
	}
	int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		//右边先走，找小
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//左边找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
		Swap(&a[left], &a[keyi]);
		keyi = left;
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
}