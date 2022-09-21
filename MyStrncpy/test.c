#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
char* strncpys(char* dest, char* src, size_t n)
{
	char* p = dest;
	char* pp = dest;
	int i = 0;
	while (*pp != '\0')
	{
		pp++;
	}
	while (i < n && *src != '\0')
	{
		*(p++) = *(src++);
		i++;
	}
	while (p < pp)
	{
		*p = '\0';
		p++;
	}
	
}
int main()
{
	char str1[10] = "abcdef";
	char str2[6] = "jhigk";
	int i = 0;
	strncpys(str1, str2, 3);	
	while(str1[i] != '\0')
	printf("%c", str1[i++]);
}