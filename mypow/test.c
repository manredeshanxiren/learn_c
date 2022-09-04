#define _CRT_SECURE_NO_WARNINGS 1
double myPowBranch(double n, long long k)
{
    if (k == 0)
    {
        return 1;
    }
    else if (k % 2 != 0)
    {
        double temp = myPowBranch(n, k / 2);
        return temp * temp * n;
    }
    else
    {
        double temp = myPowBranch(n, k / 2);
        return temp * temp;
    }
}
double myPow(double n, double k)
{
    if (n == 1 || k == 0)
    {
        return 1;
    }
    else if (k < 0)
    {
        return 1 / myPowBranch(n, (long long)fabs(k));
    }
    else
    {
        return myPowBranch(n, (long long)k);
    }
}




double myPowBranch(double x, long long N)
{
    double ans = 1.0;
    // 贡献的初始值为 x
    double x_contribute = x;
    // 在对 N 进行二进制拆分的同时计算答案
    while (N > 0)
    {
        if (N % 2 == 1)
        {
            // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
            ans *= x_contribute;
        }
        // 将贡献不断地平方
        x_contribute *= x_contribute;
        // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
        N = N >> 1;
    }
    return ans;
}
double myPow(double x, double N)
{
    return N >= 0 ? myPowBranch(x, N) : 1.0 / myPowBranch(x, -N);
}