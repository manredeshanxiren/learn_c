#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int a = 0, b = 0, c = 0;
    while (scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        if (a + b > c && a - b < c)
        {
            if (a == b && a == c)
            {
                printf("Equilateral triangle!\n");
            }
            else if (a == b || a == c || b == c)
            {
                printf("Isosceles triangle!\n");
            }
            else
            {
                printf("Ordinary triangle!\n");
            }
        }
        else
        {
            printf("Not a triangle!\n");
        }

    }
    return 0;
}