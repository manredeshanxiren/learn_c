#define _CRT_SECURE_NO_WARNINGS 1
#include"BeelzebubLanguage.h"

//栈的初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;


}

//入栈
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