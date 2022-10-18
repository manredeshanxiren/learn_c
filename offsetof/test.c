#define _CRT_SECURE_NO_WARNINGS 1
#define OffSetOf(StructType, MemberName) (size_t)&(((StructType *)0)->MemberName)
#include<stdio.h>
struct exam {
	char a;
	char b[10];
	char c;
};
int main()
{

	printf("OffSetOf(struct exam, a) is %d \n", (int)OffSetOf(struct exam, a));
	printf("OffSetOf(struct exam, b) is %d \n", (int)OffSetOf(struct exam,b));
	printf("OffSetOf(struct exam, c) is %d \n", (int)OffSetOf(struct exam, c));


	return 0;
}