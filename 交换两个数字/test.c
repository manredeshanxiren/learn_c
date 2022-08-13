#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void swap(int* a, int* b)
{
	*a = *a ^ *b;   
	*b = *a ^ *b;
	*a = *a ^ *b;
}
int main()
{
	int a;
	int b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d", a, b);
}