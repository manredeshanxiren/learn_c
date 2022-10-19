#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
size_t min(int x, int y)
{
    return x >= y ? y : x;
}
int fib(int n)
{
    if (n <= 2)
    {
        return n - 1;
    }
    else
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    int x1 = 0;//用于存储小的
    int x2 = 0;//用于存储大的
    scanf("%d", &n);
    int i = 1;
    while (fib(i) < n)
    {
        x1 = fib(i);
        i++;
    }
    x2 = fib(i);
    printf("%d", min(abs(n - x1), abs(n - x2)));
        return 0;
}