#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
    char arr[101] = { 0 };
    char brr[101] = { 0 };
    int left = 0;//ǰָ��
    int right = 0;//��ָ��
    int len = 0;
    int j = 0;
    int x = 0;
    gets(arr);
    //��ȷ�������õ��ַ����ĳ���
    //Ȼ��ȷ��һ���µĵȳ��ȵ��ַ���
    //һ������һ�����ʵķŽ���һ���ַ���
    //����ӡ���ַ���
    len = strlen(arr);
    right = len - 1;//�ú�ָ��������һ���ַ���
    left = right;//��ǰ��ָ�����һ��
    while (right > 0)
    {
        //1.����leftָ���ƶ���������ո��ֹͣ
        //�������leftָ���ֹͣ����������
        //һ�������ո񣬶������ַ�����ͷҲ����leftָ��arr��ʱ���ֹͣ
        //2.�ú�����ָ��֮��[left, right]�ĵ���copy����һ���ַ�����
        //��right����left - 2
        //left-2;
        //�ظ�����ѭ��
        while ((left != 0) && (arr[left - 1] != ' '))
        {
            left--;
        }
        for (int i = left; i <= right; i++)
        {
            brr[j++] = arr[i];
        }
        if (left != 0)//��ζ�Ż�û�н���������һ������
        {
            brr[j++] = ' ';
            right = left - 2;//����óȻ����right = 0�Ͳ���
            left--;
            if (right <= 0 && left == 1)//�ų���һ������ֻ��һ����ĸ�����
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