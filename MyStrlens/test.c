#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
size_t MyStrlen(const char* s)
{
	int count = 0;
	char* str = s;
	while (*str++)
	{
		count++;
	}
	return count;
}
int main()
{
	printf("%d", MyStrlen("abcdef"));
	return 0;
}