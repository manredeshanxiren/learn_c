#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
char* MyStrcat(char* dst, const char* src)
{
	assert(dst && src);
	char* ret = dst;
	while (*dst)	
	dst++;
	while ((*dst++ = *src++)!= '\0');
	return ret;
}
int main()
{
	char arr[20] = { "abc" };
	char arr1[20] = { "defgh" };
	printf("%s", MyStrcat(arr, arr1));
	return 0;
}