#include<iostream>
using namespace std;
#define ADD(A,B) ((A) + (B))

inline int add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a'; 
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;

	int arr []= { 1,2,2,3,34,4,5, 5,34};
	for (auto x : arr)
	{
		cout << x << " ";
	}
	cout << endl;



	//printf("%d\n", ADD(1,2));
	//cout <<ADD(5, 6)<< endl;


	//int a = 10;

	//int& ra = a;
	//ra = 20;

	//int* pa = &a;
	//*pa = 20;



	////指针和引用。复制/初始化，权限只能缩小不能放大。
	////权限放大
	//const int c = 2;
	//int& d = c;

	//const int* p1 = NULL;
	//int* p2 = p1;

	////权限保持
	//const int c = 2;
	//const int& d = c;

	//const int* p1 = NULL;
	//const int* p2 = p1;
	//
	////权限缩小
	//int x = 1;
	//const int& y = x;

	//int* p3 = NULL;
	//const int* p4 = p3;
	//int& ret = add(1, 2);
	//add(3,4);
	//cout << "add(1,2) is:" << ret << endl;
	//cout << "add(1,2) is:" << ret <<endl;
	//int a = 0;
	//int& b = a;
	//int& c = a;
	//cout << &a << endl;
	//cout << &b << endl;
	//cout << &c << endl;
	return 0;
}