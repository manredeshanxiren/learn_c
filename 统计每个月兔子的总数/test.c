#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int feibo(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return feibo(n - 1) + feibo(n - 2);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", feibo(n));
    return 0;
}