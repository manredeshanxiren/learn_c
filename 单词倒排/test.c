#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void reverse(char* str, int len)
{
    int left = 0;
    int right = len;
    while (left < right)
    {
        char ch = str[left];
        str[left] = str[right];
        str[right] = ch;
        left++;
        right--;
    }
}
int main()
{
    char str[10001];
    gets(str);
    int left = 0;
    int right = 0;
    int len = strlen(str) - 1;
    //�ȱ����ַ���
    //�Ѳ�����ĸ�Ķ��ÿո��滻
    for (int i = 0; i <= len; i++)
    {
        if (0 == (((str[i] <= 'z') && (str[i] >= 'a')) || ((str[i] <= 'Z') && (str[i] >= 'A'))))
        {
            str[i] = ' ';
        }
    }
    //�ȷ�ת�����ַ���
    reverse(str, len);
    //Ȼ���������ת����
    while (left < len)
    {
        while ((str[right + 1] != ' ') && (str[right + 1] != '\0'))
        {
            right++;
        }
        //����reverse
        reverse(&(str[left]), right - left);
        left = right + 2;
        right = left;
    }
    puts(str);
    return 0;
}