#define _CRT_SECURE_NO_WARNINGS 1
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int pnum1 = m - 1;
    int pnum2 = n - 1;
    int i = m + n - 1;
    while (pnum1 >= 0 && pnum2 >= 0)
    {
        if (nums1[pnum1] > nums2[pnum2] || pnum2 < 0)
        {
            nums1[i--] = nums1[pnum1--];
        }
        else if (nums2[pnum2] >= nums1[pnum1] || pnum1 < 0)
        {
            nums1[i--] = nums2[pnum2--];
        }
    }
    while (pnum2 >= 0)
    {
        nums1[i--] = nums2[pnum2--];
    }
}