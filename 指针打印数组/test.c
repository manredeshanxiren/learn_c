#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//写一个函数打印arr数组的内容，不使用数组下标，使用指针。

//arr是一个整形一维数组。
void print(int* arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", *(arr + i));

    }
}

int main()
{
    int arr[] = { 1 ,2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    print(arr, sz);
    return 0;
}