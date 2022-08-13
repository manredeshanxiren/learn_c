#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//ÊµÏÖstrlenº¯Êý
int MyStrlen(char* arr)
{
	int count = 0;
	while (*arr++)
	{
		count++;
	}
	return count;
}
int main()
{
	char arr[] = { "abcdefg" };
	printf("%d", MyStrlen(arr));
}