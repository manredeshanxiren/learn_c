#define _CRT_SECURE_NO_WARNINGS 1
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int max = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != 0)
            nums[i] += nums[i - 1];
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
        }
    }
    return max;
}