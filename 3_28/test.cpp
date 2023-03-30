#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
using namespace std;

void TestDate1()
{
	Date d1(2023, 3, 28);
	d1.Print();
	Date d2 = d1 + 100;
	d2.Print();
	Date d3 = d1 + 100;
	d3.Print();
	Date d4 = d1 - 100;
	d4.Print();
}
int main()
{
	TestDate1();
	Date d1(2023, 3, 28);
	Date d2(2000, 3, 28);

	cout << d1 - d2 << endl;
	cout << d1 << d2 << endl;

	return 0;
}