#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
void func(char* p) { p = p + 1; }
int main()
{
	char s[] = { '1', '2', '3', '4' };
	func(s);
	printf("%c", *s);
	return 0;
}
