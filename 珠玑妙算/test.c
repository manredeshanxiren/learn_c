#define _CRT_SECURE_NO_WARNINGS 1
int* masterMind(char* solution, char* guess, int* returnSize)
{
    int sum = 0;
    int sum1 = 0;
    int* ret = (int*)malloc(sizeof(int) * 2);
    int* hash1 = (int*)calloc(90, sizeof(int));
    int* hash2 = (int*)calloc(90, sizeof(int));
    for (int i = 0; i < 4; i++)
    {
        hash1[solution[i]]++;
        hash2[guess[i]]++;
        if (solution[i] == guess[i])
        {
            sum1++;
        }
    }
    //判断总的猜中个数
    for (int i = 65; i < 90; i++)
    {
        if (hash1[i] && hash2[i])
        {
            sum += (hash1[i] > hash2[i] ? hash2[i] : hash1[i]);
        }
    }
    *returnSize = 2;
    ret[1] = sum - sum1;
    ret[0] = sum1;
    return ret;
}