#define _CRT_SECURE_NO_WARNINGS 1
//创建一个整形数组，完成对数组的操作
//
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
#include<stdio.h>
void init(int* a, int n)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		a[i] = 0;
	}
}
void print(int* a, int n)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void reverse(int* arr, int n)
{
	int i = 0;
	while (i < n / 2)
	{
		int a;
		a = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = a;
		i++;
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	reverse(arr, 10);
	print(arr, 10);
	init(arr, 10);
	print(arr, 10);
	return 0;
}