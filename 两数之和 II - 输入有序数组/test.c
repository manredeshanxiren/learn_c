#define _CRT_SECURE_NO_WARNINGS 1
//����һ���±�� 1 ��ʼ����������?numbers ���������Ѱ� �ǵݼ�˳������? ��������������ҳ��������֮�͵���Ŀ����?target ������������������������ֱ��� numbers[index1] �� numbers[index2] ���� 1 <= index1 < index2 <= numbers.length ��
//
//	��Դ�����ۣ�LeetCode��
//	���ӣ�https ://leetcode.cn/problems/two-sum-ii-input-array-is-sorted
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������



//˫ָ�뷨
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int left = 0;//��ָ��ӵ�һ�����ֿ�ʼ
    int right = numbersSize - 1;//��ָ������һ�����ֿ�ʼ
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


//���ַ�

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

���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solution/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leet-2/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������