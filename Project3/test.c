#define _CRT_SECURE_NO_WARNINGS 1
//汉诺塔问题
#include<stdio.h>
void move(char a, char c)
{
    printf("%c-->%c\n", a, c);
}
void han(int n, char a, char b, char c)
{
    if (n == 1)
        move(a, c);//只有一个盘子的时候直接从a移动到c
    else       //如果盘子数大于1就调用递归
    {
        han(n - 1, a, c, b);//借助c将a上的（n - 1）个盘子移动到b上
        move(a, c);   //在将最后一个最大的盘子挪到c上
        han(n - 1, b, a, c);//最后借助a将b上的（n - 1）个盘子挪动到c上
    }
}
int main()
{
    int n;
    char a = 'a', b = 'b', c = 'c';
    scanf_s("%d", &n);
    han(n, a, b, c);
    return 0;
}