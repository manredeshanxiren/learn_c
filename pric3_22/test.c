#define _CRT_SECURE_NO_WARNINGS 1
//读入一个字符串str，输出字符串str中的连续的数字符串
// 
#include<stdio.h>
#include<string.h>
char* gets(char* str);
void trans(char* scr, char* dest, int begin, int end)
{
    int j = 0;
    for (int i = begin; i < end; i++)
    {
        dest[j++] = scr[i];
    }
}
int main()
{
    char str[256] = { 0 };
    char s[256] = { 0 };
    int max = 0;//记录当前遇到的最大数字子串
    int left = 0;
    int right = 0;
    gets(str);
    while (right < strlen(str))
    {
        //right寻找数字字符并且保持不能越界
        while (!(str[right] >= '0' && str[right] <= '9'))
        {
            if (right < strlen(str))
            {
                right++;
            }
            else
            {
                break;
            }
        }
        left = right;
        while ((str[right] >= '0' && str[right] <= '9') && (right < strlen(str)))
        {
            right++;
        }
        //找到一个连续的数字子串
        if (max < right - left)
        {
            max = right - left;
            trans(str, s, left, right);
        }
    }
    puts(s);
    return 0;
}

