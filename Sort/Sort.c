#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"stack.h"

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
		gap = gap /= 2;
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

//三数选择
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

//快速排序
void QuickSort(int* a, int begin, int end)
{
	////如果区间不存在就直接返回
	//if (begin >= end)
	//{
	//	return;
	//}

	////如果是小区的话那么我们就采用插入排序的方法；
	//if ((end - begin + 1) < 15)
	//{
	//	InsertSort(a + begin, end - begin + 1);
	//}

	//	int keyi = PartSort3(a, begin, end);
	//
	//	QuickSort(a, begin, keyi - 1);
	//	QuickSort(a, keyi + 1, end);


	//三路划分
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

//hoare法
int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
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
	return left;
}

//挖坑法
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int left = begin, right = end;
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//右边先走，找小
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		//左边找大
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

//前后指针法
int PartSort3(int* a, int begin, int end)
{
	//1.cur指针找比key小的，找到后停下来
	//2.prev++,交换prev和cur的值
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int prev = begin, cur = begin + 1;
	int key = begin;
	while (cur <= end)
	{
		//如果遇到小于key的值就进行交换
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

//快速排序（非递归）
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
		//进行排序
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

//归并排序
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	//递归的截止条件
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	//分成两个区间开始递归[begin, mid]/[mid+1, end];
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并
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
	//迁移剩下的部分
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end1)
	{
		tmp[i++] = a[begin2++];
	}
	//转移数据
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

	// 归并每组数据个数，从1开始，因为1个认为是有序的，可以直接归并
	int rangeN = 1;
	while (rangeN < size)
	{
		for (int i = 0; i < size; i += 2 * rangeN)
		{
			// [begin1,end1][begin2,end2] 归并
			int begin1 = i, end1 = i + rangeN - 1;
			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
			int j = i;

			// end1 begin2 end2 越界
			// 修正区间  ->拷贝数据 归并完了整体拷贝 or 归并每组拷贝
			if (end1 >= size)
			{
				end1 = size - 1;
				// 不存在区间
				begin2 = size;
				end2 = size - 1;
			}
			else if (begin2 >= size)
			{
				// 不存在区间
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

		// 也可以整体归并完了再拷贝
		memcpy(a, tmp, sizeof(int) * (size));
		rangeN *= 2;
	}

	free(tmp);
	tmp = NULL;
}