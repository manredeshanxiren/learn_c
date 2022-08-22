#define _CRT_SECURE_NO_WARNINGS 1
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int* hash = (int*)calloc(numsSize + 1, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        hash[nums[i]]++;
    }
    int x = 0;
    for (int i = 1; i <= numsSize; i++)
    {
        if (hash[i] == 0)
        {
            hash[x++] = i;
            *returnSize += 1;
        }
    }
    return hash;
}