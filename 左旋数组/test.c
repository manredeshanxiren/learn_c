#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_STRING 100
#include<stdio.h>
#include<string.h>
//左旋数组
//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
void LeftHandedArray(char* arr, int k, int arrSize)
{
	//思路来源于leetcode
	//右旋数组
	//由于将当前字符串左旋，就相当于将左旋后的字符串进行右旋；
	char brr[MAX_STRING] = { 0 };
	for (int i = 0; i < arrSize; i++)
	{
		brr[i] = arr[(i + k) % arrSize];//所以可得此行代码思路
	}
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = brr[i];
	}
}
#include<stdio.h>
int main()
{
	char arr[] = { "ABCD" };
	int k = 0;
	int arrSize = strlen(arr);
	scanf("%d", &k);
	LeftHandedArray(arr, k, arrSize);
	printf("%s", arr);
}