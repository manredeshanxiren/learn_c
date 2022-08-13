#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
    char arr[101] = { 0 };
    char brr[101] = { 0 };
    int left = 0;//前指针
    int right = 0;//后指针
    int len = 0;
    int j = 0;
    int x = 0;
    gets(arr);
    //先确定待逆置的字符串的长度
    //然后确定一个新的等长度的字符串
    //一个单词一个单词的放进另一个字符串
    //最后打印该字符串
    len = strlen(arr);
    right = len - 1;//让后指针放在最后一个字符上
    left = right;//将前后指针放在一起
    while (right > 0)
    {
        //1.先让left指针移动如果遇到空格就停止
        //这个过程left指针的停止条件有两个
        //一，遇到空格，二，到字符串开头也就是left指向arr的时候就停止
        //2.让后将两个指针之间[left, right]的单词copy到另一个字符串。
        //将right等于left - 2
        //left-2;
        //重复以上循环
        while ((left != 0) && (arr[left - 1] != ' '))
        {
            left--;
        }
        for (int i = left; i <= right; i++)
        {
            brr[j++] = arr[i];
        }
        if (left != 0)//意味着还没有结束，还有一个单词
        {
            brr[j++] = ' ';
            right = left - 2;//所以贸然的让right = 0就不行
            left--;
            if (right <= 0 && left == 1)//排除第一个单词只有一个字母的情况
            {
                right = left;
            }
        }
        else
        {
            right = left;
        }
    }
    printf("%s", brr);
}