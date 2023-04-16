#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

template <typename T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}
int main()
{
	int a = 1;
	int b = 2;
	Swap(a, b);
	double c = 1.123;
	double d = 1.345;
	Swap(c, d);
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;

	return 0;
}