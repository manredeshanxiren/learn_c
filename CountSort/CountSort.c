#define _CRT_SECURE_NO_WARNINGS 1
#include"CountSort.h"

//����ռ�
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

//��������
void CountSort(int* arr, int size)
{
	//�����ҳ����ֵ����Сֵ
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
	//�������ֵ��Сֵ����ռ�
	int* temp = GetMemory(max - min + 1);
	//�������飬ͳ�������е�Ԫ�أ�����ŵ�����Ŀռ���
	for (int i = 0; i < size; i++)
	{
		temp[arr[i] - min]++;
	}
	//����ͳ�ƽ�������ݷŻ�arr������
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


