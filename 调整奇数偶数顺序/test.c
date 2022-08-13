#define _CRT_SECURE_NO_WARNINGS 1
//输入一个整数数组，实现一个函数，
//
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//
//所有偶数位于数组的后半部分。
void SwapArr(int* arr)
{
	int sz = 10;
	int fast = 1;//快指针
	int last = 0;//慢指针
	while (fast < sz && last < sz)
	{
		if (arr[last] % 2 == 0 && arr[fast] % 2 == 1)//如果满指针指向偶数，快指针指向奇数，就交换数字，且让指针都向前移动
		{
			int t = arr[last];
			arr[last] = arr[fast];
			arr[fast] = t;
			fast++;
			last++;
		}
		if (arr[fast] % 2 == 0)//快指针找奇数
		{
			fast++;
		}
		if (arr[last] % 2 == 1)//慢指针找偶数
		{
			last++;
		}
	}
}
#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	SwapArr(arr);
	for (int i = 0; i < 10; i++)
	{
		printf("%d  ", arr[i]);
	}
}