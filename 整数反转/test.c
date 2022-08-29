#define _CRT_SECURE_NO_WARNINGS 1
int reverse(int x)
{
    long long sum = 0;
    int temp = x;
    while (temp != 0)
    {
        sum *= 10;
        sum += temp % 10;
        temp /= 10;
    }
    if (sum > 2147483647 || sum < -2147483647)
        return 0;
    return sum;
}