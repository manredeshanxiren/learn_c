#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    //观察可以发现m^2在每一个序列的中间（不知道什么原理）
    //奇数的话就是在中间，偶数的话就是中间两个奇数的平均值
    //由此原理，可以直接打印结果
    int n;
    int sum = 0;
    int arr[100];
    int mid = 0;
    int start = 0;
    scanf("%d", &n);
    mid = n * n;
    start = mid - (n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d", start);
        if (i < n - 1)
        {
            printf("+");
        }
        start += 2;
    }
    return 0;
}