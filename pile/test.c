#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
void test1()
{
	HP  heap;
	HeapInit(&heap);
	int a[] = { 1, 3, 21 ,45, 56, 78, 65, 23, 55 };
	int n = sizeof(a) / sizeof(int);
	HeapSort(a, n);


}
void test2()
{
	//造数据
	int n = 1000;
	int k = 5;
	srand((unsigned int)time(NULL));
	FILE* fin = fopen("data.txt", "w");
	if (fin == NULL)
	{
		perror("fopen failed");
		exit(-1);
	}
	for (int i = 0; i < n; i++)
	{
		int val = rand();
		fprintf(fin, "%d\n", val);
	}
	fclose(fin);


	HPDataType  minheap[5];
	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen failed");
		exit(-1);
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}

	//建立一个小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minheap, k, i);
	}
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minheap[0])
		{
			minheap[0] = val;
			AdjustDown(minheap, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}
	fclose(fout);
}
int main()
{
	//test1();

	//测试topK
	test2();



	return 0;
}