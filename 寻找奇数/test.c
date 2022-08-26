#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        x ^= arr[i];
    }
    printf("%d", x);
    return 0;
}