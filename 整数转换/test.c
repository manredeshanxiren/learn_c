#define _CRT_SECURE_NO_WARNINGS 1
int convertInteger(int A, int B)
{
    int c = A ^ B;
    //ͳ��c�Ķ��������м���1
    int i = 0;
    int count = 0;
    while (i < 32)
    {
        if (((c >> i) & 1) != 0)
            count++;
        i++;
    }
    return count;
}