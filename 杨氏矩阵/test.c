#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 4
#define COL 4
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递
// 增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
#include<stdio.h>
int Search(int array[][COL], int row, int col, int x)
{
    int i = 0;
    int j = col - 1;
    while (i <= row && j >= 0) {
        if (x < array[i][j]) {
            j--;
        }
        else if (x > array[i][j]) {
            i++;
        }
        else {
            //说明找到了
            return 1;
        }
    }
    //说明没找到
    return 0;
}
int main()
{
	int arr[5][5] = { { 1, 2, 3, 4, 5 }, 
                      {6, 7, 8, 9, 10},
                      {11, 12, 13, 14, 15},
                      {16, 17, 18, 19, 20},
                      {21, 22, 23, 24 ,} };
	int target;
    int row = 5;
    int col = 5;
	scanf("%d", &target);
    if (1 == Search(arr, row, col, target))
    {
        printf("找到了");
    }
    else
    {
        printf("没找到");
    }
	return 0;
}