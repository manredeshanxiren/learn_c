#define _CRT_SECURE_NO_WARNINGS 1
int findPeakElement(int* nums, int numsLen)
{
    int left = 0;
    int right = numsLen - 1;
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        //·åÖµÔÚ×ó±ß
        if (nums[mid] > nums[mid + 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}