#define _CRT_SECURE_NO_WARNINGS 1
//∑«µ›πÈ µœ÷strlen
#include<stdio.h>
int Mystrlen(char* str)
{
	int count = 0;
	while (str[0] != '\0')
	{
		str++;
		count++;
	}
	return count;
}
int main()
{
	char arr[] = { "abcdef" };
	printf("%d", Mystrlen(arr));
}