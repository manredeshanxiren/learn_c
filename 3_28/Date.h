#pragma once

#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
public:
	friend ostream& operator << (ostream& out, const Date& d);
	Date(int year = 1900, int month = 1, int day = 1);
	void Print();
	bool operator == (const Date& d);
	bool operator != (const Date& d);
	bool operator < (const Date& d);
	bool operator <= (const Date& d);
	bool operator > (const Date& d);
	bool operator >= (const Date& d);
	Date& operator = (const Date& d);
	Date& operator += (int day);
	Date& operator -= (int day);
	Date operator + (int day);
	Date operator - (int day);
	int operator - (Date& d);
	Date& operator++ ();
	Date operator++ (int);
	Date& operator -- ();
	Date operator -- (int);

private:
	int _year = 1900;
	int _month = 1;
	int _day  = 1;
};