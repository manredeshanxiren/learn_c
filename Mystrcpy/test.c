#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
char* MyStrcpy(char* s1,const char* s2)
{
	assert(s1 && s2);
	char* str1 = s1;
	while (*s1++ = *s2++);
	return str1;
}
int main()
{
	char arr[20] = { "abc" };
	char arr1[20] = { "defgh" };
	printf("%s", MyStrcpy(arr, arr1));
	return 0;
}