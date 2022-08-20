#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
    int hash[128];
    int ans = 0;
    memset(hash, 0, sizeof(hash));
    char ch[500];
    gets(ch);
    int len = strlen(ch);
    for (int i = 0; i < len; i++)
    {
        hash[ch[i]]++;
    }
    for (int i = 0; i < 128; i++)
    {
        if (hash[i])
        {
            ans++;
        }
    }
    printf("%d", ans);
}