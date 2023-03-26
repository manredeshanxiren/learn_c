#define _CRT_SECURE_NO_WARNINGS 1
//把字符串转换成整数
class Solution {
public:
    int StrToInt(string str)
    {
        if (str.length() <= 0)
        {
            return 0;
        }
        int sum = 0;
        int s = -1;
        if (str[0] == '-')
        {
            s = -1;
        }
        else
        {
            s = 1;
        }
        for (int j = (str[0] == '+' || str[0] == '-') ? 1 : 0; j < str.length(); j++)
        {
            if (!((str[j] >= '0') && (str[j] <= '9')))
            {
                return 0;
            }
            sum = sum * 10 + (str[j] - '0');
        }
        return sum * s;
    }
};
//不要二
#include<stdio.h>
int main()
{
    int arr[1000][1000] = { 0 };
    int x = 0;
    int y = 0;
    int count = 0;
    scanf("%d%d", &x, &y);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            arr[i][j] = 1;
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
                if (i + 2 < x)
                {
                    arr[i + 2][j] = 0;
                }
                if (j + 2 < y)
                {
                    arr[i][j + 2] = 0;
                }
            }

        }
    }
    printf("%d", count);
    return 0;
}