#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
char* MyStrstr(const char* s1, const char* s2)
{
	char* str2 = s2;
	char* p = s1;
	while (*p)
	{
		s1 = p;
		s2 = str2;
		while (*s1 != '\0'&& *s2 != '\0'&& * s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return p;
		p++;
	}
	return NULL;
}
int main()
{
	char* arr = { "abbbcd" };
	char* arr1 = { "bc" };
	printf("%s", MyStrstr(arr, arr1));
	return 0;
}