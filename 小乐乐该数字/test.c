#define _CRT_SECURE_NO_WARNINGS 1
//С����ϲ�����֣�����ϲ��0��1�������ڵõ���һ���������ÿλ����
//���0��1�����ĳһλ���������Ͱ������1�������ż������ô�Ͱ������0��
//����ش������õ������Ƕ��١�
#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    int arr[10] = { 0 };
    int i = 0;
    int sum = 0;
    scanf("%d", &a);
    while (a)
    {
        arr[i++] = a % 10;
        a /= 10;
    }
    while (i--)
    {
        sum += pow(10, i) * (arr[i] % 2);
    }
    printf("%d", sum);
    return 0;
}