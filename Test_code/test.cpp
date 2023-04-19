#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
string addStrings(string num1, string num2)
{
    string ret;
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    int next = 0;
    int j = 0;
    ret.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);
    while (end1 >= 0 || end2 >= 0)
    {
        int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
        int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
        int sum = val1 + val2 + next;
        next = sum / 10;
        sum %= 10;
        ret += (sum + '0');
        --end1;
        --end2;
    }
    if (next == 1)
    {
        ret += '1';
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string multiply(string num1, string num2)
{
    string ret("0");
    if (num1[0] == '0' || num2[0] == '0')
    {
        return ret;
    }

    int val1 = 0;
    int val2 = 0;
    int next = 0;
    int sum = 0;
    string temp;
    for (int i = num2.size() - 1; i >= 0; --i)
    {
        val2 = num2[i] - '0';
        next = 0;
        for (int j = num1.size() - 1; j >= 0; --j)
        {
            val1 = num1[j] - '0';
            sum = val1 * val2 + next;
            next = sum / 10;
            temp.insert(0, 1, (sum % 10) + '0');
        }
        cout << temp << endl;
        //ÒÆÎ»
        for (int x = i; x < num2.size() - 1; x++)
        {
            temp.push_back('0');
        }
        if (next != 0)
        {
            temp.insert(0, 1, next + '0');
        }
        ret = addStrings(temp, ret);

        temp.clear();
    }

    return ret;
}
int main()
{
    string s1("999");
    string s2("999");
    string s3 = multiply(s1, s2);
    cout << s3 << endl;

        return 0;
}