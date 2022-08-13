#define _CRT_SECURE_NO_WARNINGS 1
//递归实现数组逆置，且不用字符串库函数
#include<stdio.h>
int my_len(char* arr)
{
	if (*arr == '\0')
		return 0;
	else
		return 1 + my_len(arr + 1);
}
void reverse_string(char* arr)
{
	char ans;
	int len = my_len(arr) - 1;
	ans = *arr;//把第一个字符临时存储在ans
	*arr = *(arr + len);//将最后一个字符给到第一个字符
	*(arr + len) = '\0';//将最后一个字符先置成0
	if (len >= 2)
	{
		reverse_string(arr + 1);
	}
	*(arr + len) = ans;
}
int main()
{
	char arr[] = { 0 };
	scanf("%s", arr);
	reverse_string(arr);
	printf("%s", arr);
}

