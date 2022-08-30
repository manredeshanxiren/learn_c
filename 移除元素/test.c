#define _CRT_SECURE_NO_WARNINGS 1
int removeElement(int* nums, int numsSize, int val)
{
    int left = 0;
    int right = 0;
    while (right < numsSize)
    {   //left��Ŀ��ֵ
        while (left < numsSize && nums[left] != val)
        {
            left++;
        }
        right = left;
        //�ҷ�Ŀ��ֵ
        while (right < numsSize && nums[right] == val)
        {
            right++;
        }
        if (right < numsSize)
        {
            int t = nums[right];
            nums[right] = nums[left];
            nums[left] = t;
        }
    }
    return left;
}