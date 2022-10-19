#define _CRT_SECURE_NO_WARNINGS 1
#define A "sae"
#define B "t"A"d"A

#include"BeelzebubLanguage.h"

int main()
{
	ST st;
	StackInit(&st);
	char ch;
	char sita = '0';//用于存储θ
	//用换行符结束输入
	while ((ch = getchar()) != '\n')
	{ 
		if((!StackEmpty(&st))&&(StackTop(&st) == '(')  && sita == '0')
		{
			 sita = ch;
			 continue;
		}
		StackPush(&st, ch);
	}
	while (!StackEmpty(&st))
	{
		if (islower(StackTop(&st)))
		{
			printf("%c", sita);
			printf("%c", StackTop(&st));
		}
		else if(StackTop(&st) == 'B')
		{
			printf("%s", B);
		}
		else if (StackTop(&st) == 'A')
		{
			printf("%s", A);
		}
		else if (StackTop(&st) == '(')
		{
			printf("%c", sita);
		}
		StackPop(&st);
	}
	return 0;
}