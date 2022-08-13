#define _CRT_SECURE_NO_WARNINGS 1
//´òÓ¡ÁâÐÎ
#include<stdio.h>
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		//ÏÈ´òÓ¡¿Õ¸ñ
		for (int j = ((n / 2) > i ? i : (n - i) - 1); j < n / 2; j++)
		{
			printf(" ");
		} 
		//´òÓ¡ÐÇºÅ
		for (int j = (i > n / 2 ? 2 * (i - n / 2) + 1: (n - 2 * i)); j <= n; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
//(i > n / 2 ? (i):( n / 2 - i))