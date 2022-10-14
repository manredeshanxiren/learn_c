#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define change(num) ((((num) & 0xaaaaaaaa)>>1) | (((num) & 0x55555555)<<1))

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d ", change(a) );


	return 0;
}