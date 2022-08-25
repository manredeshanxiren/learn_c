#define _CRT_SECURE_NO_WARNINGS 1
int* twoSum(int* numbers, int numbersLen, int target, int* returnSize)
{
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numbersLen - 1; i++)
    {
        if (numbers[i] > target)
        {
            continue;
        }
        for (int j = i + 1; j < numbersLen; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                ret[0] = i + 1;
                ret[1] = j + 1;
                return ret;
            }
        }
    }
    return NULL;
}