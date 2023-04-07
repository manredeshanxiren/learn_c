#define _CRT_SECURE_NO_WARNINGS 1
//另类加法
class UnusualAdd {
public:
    int addAB(int a, int b)
    {
        int ans = a ^ b;
        int carry = a & b;
        while (carry != 0)
        {
            carry = carry << 1;
            int cur = ans;
            ans = ans ^ carry;
            carry = carry & cur;
        }
        return ans;
    }
};

//走方格的方案数
#include<iostream>
using namespace std;
int func(int n, int m)
{
    if (n == 1 || m == 1)
    {
        return n + m;
    }
    else
    {
        return func(n - 1, m) + func(n, m - 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << func(n, m) << endl;
    return 0;
}