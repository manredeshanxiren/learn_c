#define _CRT_SECURE_NO_WARNINGS 1
int singleNumber(int* nums, int numsSize)
{
    int bite[32] = { 0 };
    int x = 0;
    for (int j = 0; j < numsSize; j++)
        for (int i = 0; i <= 31; i++)
        {
            if ((nums[j] >> i) & 1)
            {
                bite[i]++;
            }
        }
    for (int i = 0; i < 32; i++)
    {
        if (bite[i] % 3 == 1)
        {
            x |= (1 << i);
        }
    }
    return x;
}