#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct A
{
	int a;
	short b;
	int c;
	char d;
};
struct B
{
	int a;
	short b;
	char c;
	int d;
};
int main()
{
	printf("%d %d", sizeof(struct A), sizeof(struct B));
return 0;
}