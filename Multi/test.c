#define _CRT_SECURE_NO_WARNINGS 1
#include"multi.h"
int main()
{
	mu* pa = InputFormula(1);
	//PrintFormula(pa);
	//mu* pb = InputFormula(2);
	//PrintFormula(pb);
	//mu* pc = SubFormula(pa, pb);
	//PrintFormula(pc);
	//mu* pc = SubtractFormula(pa, pb);
	//PrintFormula(pc);
	//mu* pc = MultiFormula(pa,pb);
	//PrintFormula(pc);
	//long long  x = ValueFormula(pa);
	//printf("%ld", x);
	mu* pd = DerivatFormula(pa);
	PrintFormula(pd);

	return 0;
}