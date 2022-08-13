#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//实现一个对整形数组的冒泡排序
void bublesort(int* arr)
{
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int i = 0;
    bublesort(arr);
    while (i < 10)
    {
        printf("%d ", arr[i]);
        i++;
    }
}