#define _CRT_SECURE_NO_WARNINGS 1
int removeDuplicates(int* nums, int numsSize)
{
    int last = 1;
    for (int fast = 1; fast < numsSize; fast++)
    {
        if (nums[fast] != nums[last - 1])//���������������ص�
        {
            nums[last] = nums[fast];
            last++;
        }
    }
    return last;
}