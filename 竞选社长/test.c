#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    char s = 0;
    while ((s = getchar()) != '0')
    {
        if (s == 'A')
        {
            a++;
        }
        else if (s == 'B')
        {
            b++;
        }
    }
    if (a == b)
    {
        printf("E");
    }
    else if (a > b)
    {
        printf("A");
    }
    else
    {
        printf("B");
    }
    return 0;
}