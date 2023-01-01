#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
void fun(char** p)
{
	int i;
	for (i = 0; i < 4; i++)
		printf("%s", p[i]);
} 
int main()
{
	char* s[6] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };
	fun(s);
	printf("\n");
	return 0;

}