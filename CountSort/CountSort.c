#define _CRT_SECURE_NO_WARNINGS 1
#include"CountSort.h"

//申请空间
int* GetMemory(size_t size)
{
	int* new = calloc(size, sizeof(int));
	if (new == NULL)
	{
		perror("calloc failed");
		exit(-1);
	}
	return new;
}

//计数排序
void CountSort(int* arr, int size)
{
	//首先找出最大值和最小值
	int max = arr[0], min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	//根据最大值最小值申请空间
	int* temp = GetMemory(max - min + 1);
	//遍历数组，统计数组中的元素，结果放到申请的空间中
	for (int i = 0; i < size; i++)
	{
		temp[arr[i] - min]++;
	}
	//根据统计结果将数据放回arr数组中
	int j = 0;
	for (int i = 0; i < max - min + 1; i++)
	{
		while (temp[i])
		{
			arr[j++] = i + min;
			temp[i]--;
		}
	}
}


