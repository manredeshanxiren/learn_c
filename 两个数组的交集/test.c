#define _CRT_SECURE_NO_WARNINGS 1
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    qsort(nums1, nums1Size, 4, cmp);
    qsort(nums2, nums2Size, 4, cmp);
    int* find = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int key1 = 0;
    int key2 = 0;
    *returnSize = 0;
    while (key1 < nums1Size && key2 < nums2Size)
    {
        if (nums1[key1] == nums2[key2])
        {
            if (!(*returnSize) || (nums1[key1] == nums2[key2] && nums1[key1] != find[((*returnSize) - 1)]))
            {
                find[(*returnSize)++] = nums1[key1];
            }
            key1++;
            key2++;
        }
        else if (nums1[key1] < nums2[key2])
        {
            key1++;
        }
        else
        {
            key2++;
        }
    }
    return find;
}