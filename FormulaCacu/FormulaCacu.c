#define _CRT_SECURE_NO_WARNINGS 1
#include"FormulaCacu.h"

//操作符优先级比较
char compare(char theta1, char theta2)
{
	int i = 0, j = 0;
	char pre[7][7] = {// +   -   *   /   (   )   # 
				 {'>','>','<','<','<','>','>'},
					 {'>','>','<','<','<','>','>'},
					 {'>','>','>','>','<','>','>'},
					 {'>','>','>','>','<','>','>'},
					 {'<','<','<','<','<','=','0'},
					 {'>','>','>','>','0','>','>'},
					 {'<','<','<','<','<','0','='} };

	switch (theta1) {
	case '+': i = 0; break;
	case '-': i = 1; break;
	case '*': i = 2; break;
	case '/': i = 3; break;
	case '(': i = 4; break;
	case ')': i = 5; break;
	case '#': i = 6; break;
	}

	switch (theta2) {
	case '+': j = 0; break;
	case '-': j = 1; break;
	case '*': j = 2; break;
	case '/': j = 3; break;
	case '(': j = 4; break;
	case ')': j = 5; break;
	case '#': j = 6; break;
	}
	return(pre[i][j]);
}

//栈的初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//压栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//栈的销毁
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//出栈
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

//拿到栈顶的数据
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

//栈的大小
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

//栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//计算函数
cacutype cacu(int x1, int x2, char op)
{
	switch (op)
	{
	case '+':
		return x1 + x2;
		break;
	case '-':
		return x1 - x2;
		break;
	case '*':
		return x1 * x2;
		break;
	case '/':
		return (1.0 * x1) / x2;
		break;
	default:
		return 0;
		break;
	}
}

//计算表达式的值
cacutype Calu()
{
	//建立两个栈
	ST OPDR;//存储操作数
	ST OPTR;//存储操作符
	StackInit(&OPDR);
	StackInit(&OPTR);
	StackPush(&OPTR, '#');
	char op;
	int x1 = 0, x2 = 0;
	char X;
	cacutype val = 0;


	//开始计算
	char ch = getchar();
	while (ch != '#' || StackTop(&OPTR) != '#')
	{	
		
		//入栈操作数
		if (isdigit(ch))
		{
			int data = 0;//用于操作数的压栈
			data = ch - '0';
			ch = getchar();
			while (isdigit(ch))
			{
				data = data * 10 + ch - '0';
				ch = getchar();
			}
			StackPush(&OPDR, data);
		}
		else
		{
			switch (compare( StackTop(&OPTR),ch))
			{ 
				case '<'://表示ch的优先级大于栈顶的操作符
					StackPush(&OPTR, ch);
					ch = getchar();
					break;
				case '='://表示ch的优先级等于栈顶的操作符
					StackPop(&OPTR, &X);
					ch = getchar();
					break;
				case '>':
					op = StackTop(&OPTR);
					StackPop(&OPTR, &op);
					x2 = StackTop(&OPDR);
					StackPop(&OPDR, &x2);
					x1 = StackTop(&OPDR);
					StackPop(&OPDR, &x1);
					val = cacu(x1, x2, op);
					StackPush(&OPDR, val);
					break;
			}
		}
	}
	return StackTop(&OPDR);
}