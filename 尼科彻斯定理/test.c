#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    //�۲���Է���m^2��ÿһ�����е��м䣨��֪��ʲôԭ��
    //�����Ļ��������м䣬ż���Ļ������м�����������ƽ��ֵ
    //�ɴ�ԭ������ֱ�Ӵ�ӡ���
    int n;
    int sum = 0;
    int arr[100];
    int mid = 0;
    int start = 0;
    scanf("%d", &n);
    mid = n * n;
    start = mid - (n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d", start);
        if (i < n - 1)
        {
            printf("+");
        }
        start += 2;
    }
    return 0;
}