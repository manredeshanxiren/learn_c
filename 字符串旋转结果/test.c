#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
#define MAX_STR 100

int JudefHandedStr(char* arr, char* brr, int arrSize)
{
	char crr[MAX_STR] = { 0 };
	for (int k = 1; k <= arrSize; k++)
	{
		for (int i = 0; i < arrSize; i++)
		{
			crr[(i + k) % arrSize] = arr[i];//将arr数组进行右旋
		}
		//对比两个字符串
		if (0 == strcmp(arr, crr))
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	//分析：
	//首先不管是左旋还是右旋
	//只要将字符串进行多次的右旋就会对应某次左旋
	//因此只需要将一个字符串进行strlen(str)次右旋
	//每次进行判断就可以得知是否是已知字符串旋转得到的了
	char arr[] = { "AABCD" };
	char brr[] = { "ABCDA" };
	int arrSize = strlen(arr);
	if(1 == JudefHandedStr(arr, brr, arrSize))
	{
		printf("该字符串是有已知字符串旋转得到的");
	}
	else
	{
		printf("该字符串不是由已知字符串得到的");
	}
	return 0;
}