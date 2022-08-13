#include<stdio.h>
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

//请注意 ，必须在不复制数组的情况下原地对数组进行操作。
#define N 2
int main()
{
	int nums[] = { 0, 0 };//只是给定一个{0， 0}的例子
    int last = 0; //寻找零
    int fast = 0; //寻找非零
    //先让慢指针找零
    //找到零之后停下来
    //再让快指针找非零
    //找到非零停下来
    //交换两个位置的数字(同时++两个指针)
    //直到快指针到达数组尾部
    while (fast < N && last < N)
    {
        while (*(nums + last) != 0  && last < N)
        {
            last++;
        }
        while (*(nums + fast) == 0 && fast < N)
        {
            fast++;
        }
        //交换两个数字
        if (last < N && fast < N)
        {
            int t = *(nums + last);
            *(nums + last) = *(nums + fast);
            *(nums + fast) = t;
            last++;
            fast++;
        }
    }
    return 0;
}