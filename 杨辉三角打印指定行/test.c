#define _CRT_SECURE_NO_WARNINGS 1
int* getRow(int rowIndex, int* returnSize)
{
    *returnSize = rowIndex + 1;
    int* ret = (int*)calloc((*returnSize) + 1, sizeof(int));
    ret[0] = 1;
    for (int j = 0; j <= rowIndex; j++)
        for (int i = j; i > 0; i--)
        {
            ret[i] = ret[i] + ret[i - 1];
        }
    return ret;
}