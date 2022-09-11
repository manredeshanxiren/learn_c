#define _CRT_SECURE_NO_WARNINGS 1
int mySqrt(int x)
{
    for (long long i = 1; i <= x / 2 + 1; i++)
    {
        if (i * i > x)
        {
            return i - 1;
        }
    }
    return 1;
}