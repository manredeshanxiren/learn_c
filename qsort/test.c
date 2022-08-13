#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int CmpInt(const void* a, const void* b)
{
	return (*(int *) b - *(int *) a);
}
int CmpChar(const void* a, const void* b)
{
	return (*(char*)b - *(char*)a);
}
int main()
{
	//实现对整型数组的排序
	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int (*cmp_int)(const void *, const void* ) = CmpInt;
	qsort(arr, 10, 4, cmp_int);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	//实现对字符的排序
	char ch[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	int (*cmp_char)(const void*, const void*) = CmpChar;
	qsort(ch, 10, 1, cmp_char);
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", ch[i]);
	}

	return 0;
}