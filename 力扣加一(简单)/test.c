#define _CRT_SECURE_NO_WARNINGS 1
int* plusOne(int* nums, int digitsSize, int* returnSize)
{
    *returnSize = digitsSize;
    int i = digitsSize - 1;
    //���м�һ����
    nums[digitsSize - 1] += 1;
    //��λ
    while (i > 0)
    {
        if (nums[i] > 9)
        {
            nums[i - 1] += nums[i] / 10;
            nums[i] = nums[i] % 10;
        }
        i--;
    }
    //�ж��Ƿ���Ҫ�ӳ�����
    if (nums[0] > 9)
    {
        //�ӳ�����
        *returnSize += 1;
        int* num = (int*)calloc((digitsSize + 1), sizeof(int));
        num[0] = 1;
        return num;
    }
    return nums;
}