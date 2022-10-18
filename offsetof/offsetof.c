#define _CRT_SECURE_NO_WARNINGS 1
#include"offsetof.h"


size_t OffSetOf(struct example s, char* a)
{
	return &s.a - &s;
}