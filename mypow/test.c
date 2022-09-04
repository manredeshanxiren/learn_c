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
    // ���׵ĳ�ʼֵΪ x
    double x_contribute = x;
    // �ڶ� N ���ж����Ʋ�ֵ�ͬʱ�����
    while (N > 0)
    {
        if (N % 2 == 1)
        {
            // ��� N �����Ʊ�ʾ�����λΪ 1����ô��Ҫ���빱��
            ans *= x_contribute;
        }
        // �����ײ��ϵ�ƽ��
        x_contribute *= x_contribute;
        // ���� N �����Ʊ�ʾ�����λ����������ÿ��ֻҪ�ж����λ����
        N = N >> 1;
    }
    return ans;
}
double myPow(double x, double N)
{
    return N >= 0 ? myPowBranch(x, N) : 1.0 / myPowBranch(x, -N);
}