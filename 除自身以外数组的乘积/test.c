#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int* arr = (int*)malloc(sizeof(int) * (numsSize + 1));
    (*returnSize) = numsSize;
    arr[numsSize] = 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        arr[i] = arr[i + 1] * nums[i];
    }
    for (int i = 1; i < numsSize; i++)
    {
        nums[i] = nums[i] * nums[i - 1];
    }
    arr[0] = arr[1];
    for (int i = 1; i < numsSize; i++)
    {
        arr[i] = nums[i - 1] * arr[i + 1];
    }
    return arr;
}