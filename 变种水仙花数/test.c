#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int cacu(int n)
{
    int sum = 0;
    int a = 0, b = 0;
    for (int i = 1; i <= 4; i++)
    {
        a = n % (int)pow(10, i);
        b = n / (int)pow(10, i);
        sum += a * b;
    }
    return sum;
}
int main()
{
    for (int i = 10000; i < 100000; i++)
    {
        if (i == cacu(i))
        {
            printf("%d ", i);
        }
    }
}