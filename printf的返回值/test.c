#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    printf("%d\n", (printf("Hello world!\n") - 1));
}