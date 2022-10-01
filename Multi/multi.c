#define _CRT_SECURE_NO_WARNINGS 1
#include"multi.h"

//申请新节点
mu*  GetList(int coe, int exp)
{
	mu* pnew = (mu*)malloc(sizeof(mu));
	if (pnew != NULL)
	{
		pnew->data.coe = coe;
		pnew->data.exp = exp;
		pnew->next = NULL;
		return pnew;
	}
	else 
	perror(errno);
	return NULL;
}

//输入表达式函数
mu* InputFormula(int i)
{
	int c = 0, e = 0;
	printf("请输入第%d个表达式:>", i);
	mu* head = (mu*)malloc(sizeof(mu));
	if (head != NULL)
	{
		mu* p = head;
		head->data.exp = -1;
		mu* pnew = NULL;
		do 
		{
			scanf("%d%d", &c, &e);
			mu* pnew = GetList(c, e);
			p->next = pnew;
			p = p->next;
		} while (p->data.coe != 0);
		return head;
	}
	else
	perror(errno);
	return NULL;
}

//打印表达式
void PrintFormula(mu* pa)
{
	assert(pa);
	mu* p = pa->next;
	while (p->data.coe != 0)
	{
		printf("(%d, %d)", p->data.coe, p->data.exp);
		p = p->next;
	}
	printf("\n");
}

//将两个表达式相加
mu* SubFormula(mu* pa, mu* pb)
{
	assert(pa && pb);
	mu* a = pa->next;
	mu* b = pb->next;
	mu* pc = (mu*)malloc(sizeof(mu));
	if (pc != NULL)
	{
		mu* p = pc;
		pc->data.exp = -1;
		while (a->data.coe != 0 && b->data.coe != 0)
		{
			if (a->data.exp < b->data.exp)
			{
				p->next = GetList(a->data.coe, a->data.exp);
				p = p->next;
				a = a->next;
			}
			else if (a->data.exp > b->data.exp)
			{
				p->next = GetList(b->data.coe, b->data.exp);
				p = p->next;
				b = b->next;
			}
			else if (a->data.exp == b->data.exp)
			{
				if (b->data.coe + a->data.coe != 0)
				{
					p->next = GetList(b->data.coe + a->data.coe, b->data.exp);
					a = a->next;
					b = b->next;
					p = p->next;
				}
				else
				{
					a = a->next;
					b = b->next;
				}
			}
		}
		//只有一种完的情况
		if (a->data.coe != 0 || b->data.coe != 0)
		{
			//1表达式未完
			if (a->data.coe != 0)
			{
				p->next = a;
			}
			//2表达式未完
			else if (b->data.coe != 0)
			{
				p->next = b;
			}
		}
		//都完成的情况
		else
		{
			p->next = GetList(0, b->data.exp);
		}
		return pc;
	}
	
}

//将两个表达式相减(pa- pb)
mu* SubtractFormula(mu* pa, mu* pb)
{
	assert(pa && pb);
	mu* p = pb->next;
	while (p->data.coe != 0)
	{
		p->data.coe = -p->data.coe;
		p = p->next;
	}
	return SubFormula(pa, pb);
}

//将两个表达式相乘
mu* MultiFormula(mu* pa, mu* pb)
{
	assert(pa && pb);
	mu* sum = GetList(1, -1);
	sum->next = GetList(0, 0);
	mu* a = pa->next;
	mu* b = pb->next;
	while (a->data.coe != 0)
	{
		b = pb->next;
		while (b->data.coe != 0)
		{
			mu* temp = GetList(0,-1);
			if (temp != NULL)
			{
				temp->next = GetList(a->data.coe * b->data.coe, a->data.exp + b->data.exp);
				temp->next->next = GetList(0, 0);
				sum = SubFormula(sum, temp);
				free(temp);
				temp = NULL;
			}
			b = b->next;
		}
		a = a->next;
	}
	return sum;
}

//计算多项式的值
long long  ValueFormula(mu* pa)
{
	assert(pa);
	int x = 0;
	printf("输入x的值:>");
	scanf("%d", &x);
	long long sum = 0;
	mu* a = pa->next;
	while (a->data.coe != 0)
	{
		sum += (a->data.coe * pow(x, a->data.exp));
		a = a->next;
	}
	return sum;
}

//计算多项式的导数
mu* DerivatFormula(mu* pa)
{
	assert(pa);
	mu* p = pa;
	while (p->data.coe != 0)
	{
		p->data.coe = p->data.exp * p->data.coe;
		p->data.exp = p->data.exp - 1;
		p = p->next;
	}
	return pa;
}