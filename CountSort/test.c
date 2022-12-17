#define _CRT_SECURE_NO_WARNINGS 1
#include"CountSort.h"
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	CountSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}