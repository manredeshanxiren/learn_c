#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��һֻ����Ҫ����n��̨�ף�ÿ�ο���ѡ����һ������������������n��̨��ʱ�ж���������

long qinwa(int n)
{
	if (n <= 1)
	{
		return 1;//���̨��ֻ��һ��ֻ��һ�ַ���
	}
	else
	{
		return qinwa(n - 1) + qinwa(n - 2);//��Ϊn��̨�׿��Ա��n-1�׺�n-2��̨�׷����ĺ�����ֱ�ӷ��أ�
	}
}
int main()
{
	int n;
	scanf_s("%d", &n);
	printf("%d", qinwa(n));
}