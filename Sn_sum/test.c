#define _CRT_SECURE_NO_WARNINGS 1
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//
//���磺2 + 22 + 222 + 2222 + 22222
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < 5; i++)
	{
		sum += pow(10, i) * n * (5 - i);
	}
	printf("%d", sum);
}