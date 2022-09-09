#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int MyStrcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 != '\0'&& *s2 != '\0'&& * s1 == *s2)
	{
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
int main()
{
	char* s1 = { "abcdefg" };
	char* s2 = { "abcdef"};
	printf("%d", MyStrcmp(s1, s2));
	return 0;
}