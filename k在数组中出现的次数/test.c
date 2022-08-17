#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int GetNumberOfK(int* data, int dataLen, int k)
{
    int count = 0;
    if (dataLen != 0)
    {
        int i = 0;
        while (*(data + i) <= k)
        {
            if (*(data + i) == k)
            {
                count++;
            }
            i++;
        }
    }
    return count;
}