#pragma once

#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
public:
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& out, Date& d);
	Date(int year = 1900, int month = 1, int day = 1);
	void Print() const;
	bool operator == (const Date& d) const;
	bool operator != (const Date& d) const;
	bool operator < (const Date& d) const;
	bool operator <= (const Date& d) const;
	bool operator > (const Date& d) const;
	bool operator >= (const Date& d) const;
	Date& operator = (const Date& d);
	Date& operator += (int day);
	Date& operator -= (int day);
	Date operator + (int day) const;
	Date operator - (int day) const;
	int operator - (Date& d) const;
	Date& operator++ ();
	Date operator++ (int);
	Date& operator -- ();
	Date operator -- (int);

private:
	int _year = 1900;
	int _month = 1;
	int _day  = 1;
};
inline ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << "Äê" << d._month << "ÔÂ" << d._day << "ÈÕ" << endl;
	return out;
}

inline istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}