#define _CRT_SECURE_NO_WARNINGS 1
int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
bool containsDuplicate(int* nums, int numsSize)
{
    //œ»≈≈–Ú
    qsort(nums, numsSize, 4, cmp);
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}