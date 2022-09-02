#define _CRT_SECURE_NO_WARNINGS 1
int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
{
    int len = 0; //定义一个长度为数组的长度
    int ks = k;
    int count = 0;
    int i = 0;
    int j = 0;
    int m = 0;
    int numssize = numSize - 1;
    while (ks)
    {
        ks /= 10;
        count++;
    }
    len = numSize > count ? numSize + 1 : count + 1;
    i = len - 1;
    j = len - 1;
    int* nums = (int*)calloc(len, sizeof(int));
    //加入
    while (i >= 0)
    {
        nums[i] = k % 10 + (numssize >= 0 ? num[numssize--] : 0);
        k /= 10;
        i--;
    }
    //进位
    while (j > 0)
    {
        if (nums[j] > 9)
        {
            nums[j - 1] += nums[j] / 10;
            nums[j] = nums[j] % 10;
        }
        j--;
    }
    //进位完判断数组长度
    if (nums[0] == 0)
    {
        *returnSize = len - 1;
        //缩减数组
        while (m < len - 1)
        {
            nums[m] = nums[m + 1];
            m++;
        }
    }
    else
    {
        *returnSize = len;
    }
    return nums;
}