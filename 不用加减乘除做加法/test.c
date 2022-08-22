#define _CRT_SECURE_NO_WARNINGS 1
int Add(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return Add(a ^ b, ((a & b) << 1));
    }
};


