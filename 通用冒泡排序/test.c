#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void swap(char* buf1, char* buf2, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, int NumsSize, int NumSize,int (* cmp)(const void* a, const void* b))
{
	for (int i = 0; i < NumsSize; i++)
	{
		for (int j = 0; j < NumsSize - 1 - i; j++)
		{
			//因为要兼容每种类型所以选用字符指针
			if ((cmp((char* )base + j * NumSize,(char* ) base + (j + 1) * NumSize)) > 0 )
			{
				swap((char*)base + j * NumSize, (char*)base + (j + 1) * NumSize, NumSize);
			}
		}
	}
}
int CmpInt(const void* a, const void* b)
{
	return (*(int*)b - *(int*)a);
}
int main()
{
	//实现通用的冒泡排序
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int (*cmp_int)(const void*, const void*) = CmpInt;
	bubble_sort(arr, 10, 4, cmp_int);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}