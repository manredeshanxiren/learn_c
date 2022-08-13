#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	for (int a = 0; a <= 1; a++)
	{
		for (int b = 0; b <= 1; b++)
		{
			for (int c = 0; c <= 1; c++)
			{
				for (int d = 0; d <= 1; d++)
				{
					if ((a != 1) + (c == 1) + (d == 1) + (d != 1) == 3)
					{
						printf("a = %d b = %d c = %d d = %d",a, b, c, d);
						goto end;
					}
				}
			}
		}
	}
end:
	return 0;
}