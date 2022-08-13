#define _CRT_SECURE_NO_WARNINGS 1
//给你一个下标从 1 开始的整数数组?numbers ，该数组已按 非递减顺序排列? ，请你从数组中找出满足相加之和等于目标数?target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode.cn/problems/two-sum-ii-input-array-is-sorted
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//双指针法
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int left = 0;//左指针从第一个数字开始
    int right = numbersSize - 1;//右指针从最后一个数字开始
    int* arr = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    while (left < right)
    {
        if (*(numbers + left) + *(numbers + right) == target)
        {
            arr[0] = left + 1;
            arr[1] = right + 1;
            return arr;
        }
        else if (*(numbers + left) + *(numbers + right) > target)
        {
            right--;
        }
        else  if (*(numbers + left) + *(numbers + right) < target)
        {
            left++;
        }
    }
    return arr;
}


//二分法

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    for (int i = 0; i < numbersSize; ++i) {
        int low = i + 1, high = numbersSize - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (numbers[mid] == target - numbers[i]) {
                ret[0] = i + 1, ret[1] = mid + 1;
                return ret;
            }
            else if (numbers[mid] > target - numbers[i]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    }
    ret[0] = -1, ret[1] = -1;
    return ret;
}

作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solution/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leet-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。