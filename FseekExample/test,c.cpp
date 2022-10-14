#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char s [30];
    FILE* pFile;
    pFile = fopen("example.txt", "w+");
    fputs("This is an apple.", pFile);
    fseek(pFile, 9, SEEK_SET);
    fputs(" sam", pFile); 
    rewind(pFile);
    fgets(s, 20,pFile);
    printf("%s", s);
    fclose(pFile);


    return 0;
}