#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<ctype.h>
#include<math.h>
int MyAtoi(char* str)
{
	long long num = 0;
	char* p = str;
	int i = 0;
	while (*p != '\0')
	{
		if (isdigit(*p) == 0)
		{
			return 0;
		}
		p++;
	}
	p--;
	while (p >= str)
	{
		num += pow(10, i++) * (*p - '0');
		p--;
		if (num > _CRT_INT_MAX)
		{
			return 0;
		}
	}
	return num;
}
int main()
{
	char* str1 = "999999999765432";
	printf("%d", MyAtoi(str1));
	return 0;
}