#define _CRT_SECURE_NO_WARNINGS 1
//����һ���ַ���str������ַ���str�е����������ַ���
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
    int max = 0;//��¼��ǰ��������������Ӵ�
    int left = 0;
    int right = 0;
    gets(str);
    while (right < strlen(str))
    {
        //rightѰ�������ַ����ұ��ֲ���Խ��
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
        //�ҵ�һ�������������Ӵ�
        if (max < right - left)
        {
            max = right - left;
            trans(str, s, left, right);
        }
    }
    puts(s);
    return 0;
}

