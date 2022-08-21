#define _CRT_SECURE_NO_WARNINGS 1
int JudgeNum(int num)
{
    if (num == 0 || (num % 10 == 0))
    {
        return -1;
    }
    int sum = num;
    int count = 0;
    while (sum > 0)
    {
        int x = sum % 10;
        if (x == 0)
        {
            return -1;
        }
        if (0 != (num % x))
        {
            count++;
            return count;
        }
        sum /= 10;
    }
    return count;
}
int* selfDividingNumbers(int left, int right, int* returnSize)
{
    (*returnSize) = 0;
    int* arr = (int*)malloc(sizeof(int) * right);
    for (int i = left; i <= right; i++)
    {
        if (0 == JudgeNum(i))
        {
            arr[(*returnSize)++] = i;
        }
    }
    return arr;
}