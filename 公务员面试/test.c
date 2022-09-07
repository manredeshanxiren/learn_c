#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    float arr[7] = { 0 };
    float x = 0;
    while (scanf("%f", &x) != EOF)
    {
        float sum = 0;
        int max = 0;
        int min = 0;
        int i = 0;
        arr[0] = x;
        for (int z = 1; z < 7; z++)
        {
            scanf("%f", &arr[z]);
        }
        while (i < 7)
        {
            if (arr[min] > arr[i])
            {
                min = i;
            }
            if (arr[max] < arr[i])
            {
                max = i;
            }
            i++;
        }
        arr[min] = 0;
        arr[max] = 0;
        for (int i = 0; i < 7; i++)
        {
            sum += arr[i];
        }
        sum = sum * 1.0 / 5;
        printf("%.2f\n", sum);
    }
    return 0;
}