#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct example
{
	int a;
	int b;
	int c;
 };

size_t OffSetOf(struct example s, char* a);