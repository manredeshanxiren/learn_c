#define _CRT_SECURE_NO_WARNINGS 1
//��ŵ������
#include<stdio.h>
void move(char a, char c)
{
    printf("%c-->%c\n", a, c);
}
void han(int n, char a, char b, char c)
{
    if (n == 1)
        move(a, c);//ֻ��һ�����ӵ�ʱ��ֱ�Ӵ�a�ƶ���c
    else       //�������������1�͵��õݹ�
    {
        han(n - 1, a, c, b);//����c��a�ϵģ�n - 1���������ƶ���b��
        move(a, c);   //�ڽ����һ����������Ų��c��
        han(n - 1, b, a, c);//������a��b�ϵģ�n - 1��������Ų����c��
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