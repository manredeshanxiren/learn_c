#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ӡ�������
int main()
{
	int n;
	int arr[100] = { 1 };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		//��ӡ�ո�
		for (int j = 0; j < n - i; j++)
		{
			printf(" ");
		}
		//�����ֽ�������
		for (int k = i - 1; k > 0; k--)
		{
			arr[k] = arr[k] + arr[k - 1];
		}
		//��ӡ����
		for (int z = 0; z < i; z++)
		{
			printf("%d ", arr[z]);
		}
		printf("\n");
	}

}