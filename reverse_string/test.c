#define _CRT_SECURE_NO_WARNINGS 1
//�ݹ�ʵ���������ã��Ҳ����ַ����⺯��
#include<stdio.h>
int my_len(char* arr)
{
	if (*arr == '\0')
		return 0;
	else
		return 1 + my_len(arr + 1);
}
void reverse_string(char* arr)
{
	char ans;
	int len = my_len(arr) - 1;
	ans = *arr;//�ѵ�һ���ַ���ʱ�洢��ans
	*arr = *(arr + len);//�����һ���ַ�������һ���ַ�
	*(arr + len) = '\0';//�����һ���ַ����ó�0
	if (len >= 2)
	{
		reverse_string(arr + 1);
	}
	*(arr + len) = ans;
}
int main()
{
	char arr[] = { 0 };
	scanf("%s", arr);
	reverse_string(arr);
	printf("%s", arr);
}

