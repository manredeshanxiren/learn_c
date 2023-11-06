#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"BSTree.h"


int main()
{
	int a[] = { 8 , 3 , 1, 10, 6, 4 , 7, 14, 13 };
	key :: BSTree<int> t1;

	for (auto i : a)
	{
		t1.Insert(i);
	}
	t1.Inorder();

	cout << t1.Find(4) << endl;
	t1.EraseR(4);
	t1.EraseR(8);
	t1.Inorder();
	cout << t1.FindR(14);

	return 0;
};