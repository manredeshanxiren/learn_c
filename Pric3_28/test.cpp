//#define _CRT_SECURE_NO_WARNINGS 1
//
////两种排序方法
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	string* a = new string[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	int ds = 1, ls = 1;  //ds判断字典，ls判断长度
//	//字典排序判断
//	for (int i = 1; i < n; i++)
//	{
//		if (a[i - 1] > a[i])		//前面比后面大，不符合
//		{
//			ds = 0;
//			break;
//		}
//	}
//	//长度排序判断
//	for (int i = 1; i < n; i++)
//	{
//		if (a[i - 1].size() > a[i].size())  //前面比后面长，不符合
//		{
//			ls = 0;
//			break;
//		}
//	}
//
//	if (ds == 1 && ls == 0)								//如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically"
//		cout << "lexicographically" << endl;
//	if (ds == 0 && ls == 1)								//如果根据长度排列而不是字典序排列输出"lengths",
//		cout << "lengths" << endl;
//	if (ds == 1 && ls == 1)								//如果两种方式都符合输出"both"，否则输出"none"
//		cout << "both" << endl;
//	if (ds == 0 && ls == 0)
//		cout << "none" << endl;
//
//	return 0;
//}

////最小公倍数
// 方法一
//#include<stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d %d", &a, &b);
//	int i = 1;
//	while ((a * i) % b != 0)
//	{
//		i++;
//	}
//	printf("%d\n", i * a);
//	return 0;
//}

//方法二
