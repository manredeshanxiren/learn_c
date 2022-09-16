#define _CRT_SECURE_NO_WARNINGS 1
//小乐乐喜欢数字，尤其喜欢0和1。他现在得到了一个数，想把每位的数
//变成0或1。如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0。
//请你回答他最后得到的数是多少。
#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    int arr[10] = { 0 };
    int i = 0;
    int sum = 0;
    scanf("%d", &a);
    while (a)
    {
        arr[i++] = a % 10;
        a /= 10;
    }
    while (i--)
    {
        sum += pow(10, i) * (arr[i] % 2);
    }
    printf("%d", sum);
    return 0;
}