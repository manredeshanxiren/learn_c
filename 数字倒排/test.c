#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reverse(char* str, int len)
{
    int left = 0;
    int right = len;
    while (left < right)
    {
        char ch = str[left];
        str[left] = str[right];
        str[right] = ch;
        left++;
        right--;
    }
}
int main()
{
    char nums[11] = { 0 };
    scanf("%s", nums);
    int len = strlen(nums);
    reverse(nums, len - 1);
    printf("%s", nums);
    return 0;
}