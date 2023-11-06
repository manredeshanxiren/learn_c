#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int x;
	cin >> x;

	string s = to_string(x);

	string temp = s;
	reverse(temp.begin(), temp.end());

	printf("%s", temp == s ? "yes" : "no");
	
}