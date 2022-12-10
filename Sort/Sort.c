#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"stack.h"

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
		gap = gap /= 2;
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
					end-= gap;
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

//����ѡ��
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) >> 1;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else//a[begin] < a[end] && a[end] <  a[mid]
		{
			return end;
		}
	}
	else//a[begin] > a[mid]
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[end] > a[begin])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}

//��������
void QuickSort(int* a, int begin, int end)
{
	////������䲻���ھ�ֱ�ӷ���
	//if (begin >= end)
	//{
	//	return;
	//}

	////�����С���Ļ���ô���ǾͲ��ò�������ķ�����
	//if ((end - begin + 1) < 15)
	//{
	//	InsertSort(a + begin, end - begin + 1);
	//}

	//	int keyi = PartSort3(a, begin, end);
	//
	//	QuickSort(a, begin, keyi - 1);
	//	QuickSort(a, keyi + 1, end);


	//��·����
	if (begin >= end)
	{
		return;
	}
	{
		int mid = GetMidIndex(a, begin, end);
		Swap(&a[begin], &a[mid]);

		int left = begin, right = end;
		int key = a[left];
		int cur = begin + 1;
		while (cur <= right)
		{
			if (a[cur] < key)
			{
				Swap(&a[cur], &a[left]);
				cur++;
				left++;
			}
			else if (a[cur] > key)
			{
				Swap(&a[cur], &a[right]);
				--right;
			}
			else // a[cur] == key
			{
				cur++;
			}
		}

		// [begin, left-1][left, right][right+1,end]
		QuickSort(a, begin, left - 1);
		QuickSort(a, right + 1, end);
	}
}

//hoare��
int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
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
	return left;
}

//�ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int left = begin, right = end;
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//�ұ����ߣ���С
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		//����Ҵ�
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	Swap(&a[hole], &key);
	return hole;
}

//ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	//1.curָ���ұ�keyС�ģ��ҵ���ͣ����
	//2.prev++,����prev��cur��ֵ
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int prev = begin, cur = begin + 1;
	int key = begin;
	while (cur <= end)
	{
		//�������С��key��ֵ�ͽ��н���
		if (a[cur] < a[key]  && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
			cur++;
			
	}
	Swap(&a[prev], &a[key]);
	key = prev;
	return key;
}

//�������򣨷ǵݹ飩
void QuickSortS(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st); 
		int left = StackTop(&st);
		StackPop(&st);
		//��������
		int keyi = PartSort1(a, left, right);
		if (keyi - 1 > left)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
	}
}

//�鲢����
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	//�ݹ�Ľ�ֹ����
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	//�ֳ��������俪ʼ�ݹ�[begin, mid]/[mid+1, end];
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//�鲢
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] > a[begin2])
		{
			tmp[i++] = a[begin2++];
		}
		else
		{
			tmp[i++] = a[begin1++];
		}
	}
	//Ǩ��ʣ�µĲ���
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end1)
	{
		tmp[i++] = a[begin2++];
	}
	//ת������
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}
void MergeSort(int* a, int size)
{
	int* tmp = (int*)malloc((size) * sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	_MergeSort(a, 0,  size - 1, tmp);
}

void MergeSortS(int* a, int size)
{
	int* tmp = (int*)malloc(sizeof(int) * size);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	// �鲢ÿ�����ݸ�������1��ʼ����Ϊ1����Ϊ������ģ�����ֱ�ӹ鲢
	int rangeN = 1;
	while (rangeN < size)
	{
		for (int i = 0; i < size; i += 2 * rangeN)
		{
			// [begin1,end1][begin2,end2] �鲢
			int begin1 = i, end1 = i + rangeN - 1;
			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
			int j = i;

			// end1 begin2 end2 Խ��
			// ��������  ->�������� �鲢�������忽�� or �鲢ÿ�鿽��
			if (end1 >= size)
			{
				end1 = size - 1;
				// ����������
				begin2 = size;
				end2 = size - 1;
			}
			else if (begin2 >= size)
			{
				// ����������
				begin2 = size;
				end2 = size - 1;
			}
			else if (end2 >= size)
			{
				end2 = size - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
		}

		// Ҳ��������鲢�����ٿ���
		memcpy(a, tmp, sizeof(int) * (size));
		rangeN *= 2;
	}

	free(tmp);
	tmp = NULL;
}