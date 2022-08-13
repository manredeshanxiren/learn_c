#define _CRT_SECURE_NO_WARNINGS 1
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
#include<stdio.h>
void swap(char* a, char* b)
{
	int i = 0;
	char temp;
	for(i = 0; a[i] != '\0'; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
int main()
{
	char arr[] = { "abcdef" };
	char arr1[] = { "123456" };
	swap(arr, arr1);
	printf("%s\n%s", arr, arr1);
	return 0;
}