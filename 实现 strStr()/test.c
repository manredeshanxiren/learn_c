#define _CRT_SECURE_NO_WARNINGS 1
int Mystrcmp(char* a, char* b, int x)
{
    while (x--)
    {
        if (a[x] != b[x])
        {
            return 0;
        }
    }
    return 1;
}
int strStr(char* haystack, char* needle)
{
    int needlen = strlen(needle);
    int haylen = strlen(haystack);
    int i = 0;
    while (i <= (haylen - needlen))
    {
        if (Mystrcmp(&haystack[i], needle, needlen))
        {
            return i;
        }
        i++;
    }
    return -1;
}