#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
using namespace std;

int main()
{
	try
	{
		xupt::test_string5();
	}
	catch(const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}