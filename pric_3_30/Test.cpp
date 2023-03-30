#define _CRT_SECURE_NO_WARNINGS 1
//求最大的连续bit数
#include<iostream>
using namespace std;
int main()
{
    int n;
    int max = 0;
    int flag = 0;
    cin >> n;
    for (int i = 0; i < 32; i++)
    {
        if ((1 << i) & n)
        {
            flag++;
            if (flag > max)
            {
                max = flag;
            }
        }
        else
        {
            flag = 0;
        }
    }
    cout << max << endl;
}

//最近公共祖先
class LCA {
public:
    int getLCA(int a, int b)
    {
        while (a != b)
        {
            if (a > b)
            {
                a /= 2;
            }
            else if (a < b)
            {
                b /= 2;
            }
        }
        return a;
    }
};