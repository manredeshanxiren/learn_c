#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    long n;
    long k;
    long ans = 0;
    scanf("%ld%ld", &n, &k);
    if (k == 0)
    {
        printf("%ld\n", n * n);
        return 0;
    }
    for (int j = k + 1; j <= n; j++)
    {
        ans += (j - k) * (n / j) + (n % j < k ? 0 : (n % j) - k + 1);
    }
    printf("%ld", ans);
    return 0;
}