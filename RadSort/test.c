#define _CRT_SECURE_NO_WARNINGS 1
#include"RadSort.h"
int main()
{
	int arr[] = { 123,323,543,436,764,765,977,445,765 };
	int right = sizeof(arr) / sizeof(arr[0]);
	RadSort(arr, 0, right, 3);

	return 0;
}