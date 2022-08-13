#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    int i = 3;
    scanf("%d", &n);
    while (i--)
    {
        printf("%d ", n / (int)pow(60, i));
        n -= (n / (int)pow(60, i)) * (int)pow(60, i);
    }
    
}