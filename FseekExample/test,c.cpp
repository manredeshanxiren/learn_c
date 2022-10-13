#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char s [30];
    FILE* pFile;
    pFile = fopen("example.txt", "wb");
    fputs("This is an apple.", pFile);
    fseek(pFile, 9, SEEK_SET);
    fputs(" sam", pFile);
    fclose(pFile);
    pFile = fopen("example.txt", "rb");
    fgets(s, 20,pFile);
    printf("%s", s);
    return 0;
}