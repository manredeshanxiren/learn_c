#define _CRT_SECURE_NO_WARNINGS 1
//������A�е����ݺ�����B�е����ݽ��н�����������һ����
#include<stdio.h>
void swap(char* a, char* b)
{
	int i = 0;
	char temp;
	for(i = 0; a[i] != '\0'; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
int main()
{
	char arr[] = { "abcdef" };
	char arr1[] = { "123456" };
	swap(arr, arr1);
	printf("%s\n%s", arr, arr1);
	return 0;
}