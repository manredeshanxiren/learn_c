#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//ÊµÏÖstrcpyº¯Êý
void MyStrcpy(char* dest, const char* scr)
{
	while (*dest++ = *scr++)
	{
		;
	}
}
int main()
{
	char arr[] = { "abcdefg" };
	char arr1[] = { "xxxxxxxxxxxxxxx" };
	MyStrcpy(arr1, arr);
	printf("%s", arr1);
}