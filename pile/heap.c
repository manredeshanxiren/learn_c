#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

int n;

//�ѵĳ�ʼ��
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}


//�ѵ�����
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

//��������
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType temp = *a;
	*a = *b;
	*b = temp;
}

//���ϵ���
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child >= 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//�ѵĲ���
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = (php->capacity == 0 ? 4 : php->capacity * 2);
		HPDataType* newa = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (newa == NULL)
		{
			perror("realloc of HeapPush failed ");
			exit(-1);
		}
		php->a = newa;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size - 1);
}

//�ѵĴ�ӡ
void  HeapPrint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
}

//���µ���
void AdjustDown(HPDataType* a, int size, int parent)
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

//�ѵ�ɾ��
void HeapDown(HP* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

//ȡ�Ѷ�������
void HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

//���Ƿ�Ϊ��
bool HeapEmpty(HP* php)
{
	return php->size == 0;
}

//�����ѵĺ���
void HeapCreate(HP* php, HPDataType* a, int n)
{
	assert(php);
	php->a = (HPDataType*)realloc(php->a ,sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		perror("realloc fail");
		exit(-1);
	}
	memcpy(php->a, a, sizeof(HPDataType) * n);
	php->size = php->capacity = n;
	//�����㷨
	for (int i = (n - 1 - 1) / 2; i >= 0; i++)
	{
			AdjustDown(a, n, i);
	}
}