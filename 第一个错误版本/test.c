#define _CRT_SECURE_NO_WARNINGS 1
//¶þ·Ö²éÕÒ
int firstBadVersion(int n)
{
    int left = 0;
    int right = n;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid) == 1 && isBadVersion(mid - 1) == 0)
        {
            return mid;
        }
        else if (isBadVersion(mid) == 1)
        {
            right = mid - 1;
        }
        else if (isBadVersion(mid) == 0)
        {
            left = mid + 1;
        }

    }
    return -1;

}