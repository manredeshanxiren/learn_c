#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 1;
	double sum = 0.0;
	for (int i = 1.0; i < 101; i++)
	{
		sum += (n * 1.0) / i;
		n = -n;
	}
	printf("%lf", sum);
	return 0;
}