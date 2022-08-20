#define _CRT_SECURE_NO_WARNINGS 1
//因为对于一个在数组中出现次数大于n/2次的元素
//进行排序后那么它一定会出现于数组的中间位置
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int majorityElement(int* nums, int numsSize)
{
    qsort(nums, numsSize, 4, cmp);
    return nums[numsSize / 2];
}