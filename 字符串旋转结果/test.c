#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
#define MAX_STR 100

int JudefHandedStr(char* arr, char* brr, int arrSize)
{
	char crr[MAX_STR] = { 0 };
	for (int k = 1; k <= arrSize; k++)
	{
		for (int i = 0; i < arrSize; i++)
		{
			crr[(i + k) % arrSize] = arr[i];//��arr�����������
		}
		//�Ա������ַ���
		if (0 == strcmp(arr, crr))
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	//������
	//���Ȳ�����������������
	//ֻҪ���ַ������ж�ε������ͻ��Ӧĳ������
	//���ֻ��Ҫ��һ���ַ�������strlen(str)������
	//ÿ�ν����жϾͿ��Ե�֪�Ƿ�����֪�ַ�����ת�õ�����
	char arr[] = { "AABCD" };
	char brr[] = { "ABCDA" };
	int arrSize = strlen(arr);
	if(1 == JudefHandedStr(arr, brr, arrSize))
	{
		printf("���ַ���������֪�ַ�����ת�õ���");
	}
	else
	{
		printf("���ַ�����������֪�ַ����õ���");
	}
	return 0;
}