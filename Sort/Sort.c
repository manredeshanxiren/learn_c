#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

//��ӡ����
void PrintArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
}

//��������
void Swap(int* a ,int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

//��������
void InsertSort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			//����
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

//ϣ������
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
				//����
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

//ѡ������
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
		//�ų�max��beginλ�õ����
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

//���µ���   O(N)
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

//������
void HeapSort(int* a, int size)
{
	//���򣺴��
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

//ð������
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
		//���һ��ð��û�н������ݵĻ�����ô�ͱ�ʾ�Ѿ�������
		if (flag == 0)
		{
			break;
		}
	}
}

//��������
void QuickSort(int* a, int begin, int end)
{
	//������䲻���ھ�ֱ�ӷ���
	if (begin >= end)
	{
		return;
	}
	int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		//�ұ����ߣ���С
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//����Ҵ�
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