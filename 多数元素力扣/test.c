#define _CRT_SECURE_NO_WARNINGS 1
//��Ϊ����һ���������г��ִ�������n/2�ε�Ԫ��
//�����������ô��һ���������������м�λ��
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int majorityElement(int* nums, int numsSize)
{
    qsort(nums, numsSize, 4, cmp);
    return nums[numsSize / 2];
}