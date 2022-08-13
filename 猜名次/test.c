#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int A, B, C, D, E;
	for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				for (D = 1; D <= 5; D++)
				{
					for (E = 1; E <= 5; E++)
					{
						//初步筛选：根据每位选手都说对一半
						if ((B == 2 || A == 3) + (B == 2 || E == 4) + (C == 1 || D == 2) + (C == 5 || D == 3) + (E == 4 || A == 1) == 5)
						{
							//再次筛选：因为第一层筛选结果还包含这种情况：一个人说的2句话都对。所以进行与运算的目的是把这种情况过滤掉
							if ((B == 2 && A == 3) + (B == 2 && E == 4) + (C == 1 && D == 2) + (C == 5 && D == 3) + (E == 4 && A == 1) == 0)
							{
								//第三次筛选：多滤掉出现间隔名次（比如，只有1,2,5名）的情况和并列名次的情况，让名次只有1,2,3,4,5
								if (A != B && A != C && A != D && A != E && B != C && B != D && B != E && C != D && C != E && D != E)
								{
									printf("A:%d,B:%d,C:%d,D:%d,E:%d\n", A, B, C, D, E);
									goto end;
								}

							}
							
						}
					}
				}
			}
		}
	}
	end:
	system("pause");
	return 0;
}