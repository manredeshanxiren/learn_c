#define _CRT_SECURE_NO_WARNINGS 1
//���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
#include<stdio.h>
int Judges(int s)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (s & (1 << i))
		{
			count++;
		}
	}
	return count;
}
int Judgea(int a, int b)
{
	int s = a ^ b;
	return Judges(s);
}
int main()
{
	int a = 0;
	int b = 0;
	scanf_s("%d %d", &a, &b);
	printf("%d", Judgea(a, b));
}