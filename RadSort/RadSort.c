#define _CRT_SECURE_NO_WARNINGS 1
#include"RadSort.h"


Queue q0;
Queue q1;
Queue q2;
Queue q3;
Queue q4;
Queue q5;
Queue q6;
Queue q7;
Queue q8;
Queue q9;
//��ʼ��
void Init()
{
	QueueInit(&q0);
	QueueInit(&q1);
	QueueInit(&q2);
	QueueInit(&q3);
	QueueInit(&q4);
	QueueInit(&q5);
	QueueInit(&q6);
	QueueInit(&q7);
	QueueInit(&q8);
	QueueInit(&q9);
}
Queue* q[10] = { &q0,&q1,&q2,&q3,&q4,&q5,&q6,&q7,&q8,&q9 };

//��ȡkey
int GetKey(int value, int k)
{
	int key = 0;
	while (k >= 0)
	{
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}

//������
void PushNum(int arr[], int left, int right, int k)
{
	for (int i = left; i < right; i++)
	{
		int key = GetKey(arr[i], k);
		QueuePush(q[key], arr[i]);
	}
}

//��������
void CollectNum(int arr[])
{
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		while (!QueueEmpty(q[i]))
		{
			arr[j++] = QueueFront(q[i]);
			QueuePop(q[i]);
		}
	}
}

//��ӡ����
void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
//��������
void RadSort(int arr[], int left, int right,  int k)
{
	Init();
	for (int i = 0; i < k; i++)
	{
		//������
		PushNum(arr, left, right, i);

		//��������
		CollectNum(arr);
	}

	//��ӡ���
	Print(arr, right);
}