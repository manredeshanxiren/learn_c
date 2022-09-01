#define _CRT_SECURE_NO_WARNINGS 1
//¹þÏ£±í
int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    int map[10001] = { 0 };
    int j = 0;
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++)
    {
        map[nums[i]]++;
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (map[i] == 1)
        {
            nums[j] = i;
            j++;
        }
        if (j == 2)
        {
            break;
        }
    }
    return nums;
}
//Òì»ò
int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    int x = 0, y = 0;
    int i = 0;
    int s = 0;
    for (int i = 0; i < numsSize; i++)
    {
        s ^= nums[i];
    }
    for (i = 0; i <= 31; i++)
    {
        if (s & (1 << i))
        {
            break;
        }
    }
    for (int j = 0; j < numsSize; j++)
    {
        if (nums[j] & (1 << i))
        {
            x ^= nums[j];
        }
        else
        {
            y ^= nums[j];
        }
    }
    nums[0] = x;
    nums[1] = y;
    *returnSize = 2;
    return nums;
}
