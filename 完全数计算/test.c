#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int n;
    int count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            count += 1;
        }
    }
    printf("%d", count);
    return 0;
}