#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//memcpy
void* MyMemcpy(void* dest, const void* src, size_t num)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	for (int i = 0; i < num; i++)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
//Ä£ÄâmemmoveµÄmemcpy
void* MyMemcpy_s(void* dest, const void* src, size_t num)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	if (dest < src)
	{
		while (num--)
		{
				*(char*)dest = *(char*)src;
				dest = (char*)dest + 1;
				src = (char*)src + 1;	
		}
	}
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7 ,8 , 9, 10 };
	int arr2[10] = { 0 };
	MyMemcpy(arr2, arr, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}