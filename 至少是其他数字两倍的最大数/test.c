#define _CRT_SECURE_NO_WARNINGS 1
int dominantIndex(int* nums, int numsSize)
{
    int max = 0;
    int max_s = 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > nums[max])
        {
            max_s = max;
            max = i;
        }
        else if (nums[i] > nums[max_s] && nums[i] != nums[max])
        {
            max_s = i;
        }
    }
    return nums[max] >= (nums[max_s] * 2) ? max : -1;
}