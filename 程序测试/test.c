#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char ps[101];
    int x = 0, y = 0, z = 0;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        gets(ps);
        if (strlen(ps) >= 8)
        {
            if ((ps[0] >= '0' && ps[0] <= '9') != 1)
            {
                for (int i = 0; i < strlen(ps); i++)
                {
                    if ((ps[i] >= 'A' && ps[i] <= 'Z') ||
                        (ps[i] >= 'a' && ps[i] <= 'z') ||
                        (ps[i] >= '0' && ps[i] <= '9'))
                    {
                        for (int i = 0; i < strlen(ps); i++)
                        {
                            if (ps[i] >= 'A' && ps[i] <= 'Z')
                            {
                                x = 1;
                            }
                            else if (ps[i] >= 'a' && ps[i] <= 'z')
                            {
                                y = 1;
                            }
                            else if (ps[i] >= '0' && ps[i] <= '9')
                            {
                                z = 1;
                            }
                        }
                        if (x + y + z >= 2)
                        {
                            printf("YES");
                            return 0;
                        }
                        else
                        {
                            goto end;
                        }
                    }
                    else
                    {
                        goto end;
                    }
                }

            }
            else
            {
                goto end;
            }
        }
        else
        {
            goto end;
        }
    }
end:
    printf("NO");


    return 0;
}