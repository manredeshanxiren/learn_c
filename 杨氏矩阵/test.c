#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 4
#define COL 4
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�
// ���ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);
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
            //˵���ҵ���
            return 1;
        }
    }
    //˵��û�ҵ�
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
        printf("�ҵ���");
    }
    else
    {
        printf("û�ҵ�");
    }
	return 0;
}