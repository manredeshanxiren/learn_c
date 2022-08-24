#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
    double n, m;

    while (scanf("%lf %lf", &n, &m) != EOF)
    {
        double sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += n;
            n = sqrt(n);
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}