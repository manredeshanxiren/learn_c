#define _CRT_SECURE_NO_WARNINGS 1
//����һ���������飬ʵ��һ��������
//
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//
//����ż��λ������ĺ�벿�֡�
void SwapArr(int* arr)
{
	int sz = 10;
	int fast = 1;//��ָ��
	int last = 0;//��ָ��
	while (fast < sz && last < sz)
	{
		if (arr[last] % 2 == 0 && arr[fast] % 2 == 1)//�����ָ��ָ��ż������ָ��ָ���������ͽ������֣�����ָ�붼��ǰ�ƶ�
		{
			int t = arr[last];
			arr[last] = arr[fast];
			arr[fast] = t;
			fast++;
			last++;
		}
		if (arr[fast] % 2 == 0)//��ָ��������
		{
			fast++;
		}
		if (arr[last] % 2 == 1)//��ָ����ż��
		{
			last++;
		}
	}
}
#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	SwapArr(arr);
	for (int i = 0; i < 10; i++)
	{
		printf("%d  ", arr[i]);
	}
}