#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

int GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);

	int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		return 29;
	}
	else
	{
		return monthArray[month];
	}
}
Date::Date(int year, int month, int day)
{
	if (month > 0 && month < 13
		&& (day > 0 && day < GetMonthDay(year, month)))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期非法" << endl;
	}
}
void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}


bool Date :: operator == (const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date :: operator <(const Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date :: operator <=(const Date& d)
{
	return *this < d || *this == d;
}
bool Date :: operator > (const Date& d)
{
	return !(*this <= d);
}
bool Date :: operator >= (const Date& d)
{
	return !(*this <= d) || *this == d;
}
//d1 = d2
Date& Date :: operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

Date& Date :: operator += (int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month >= 13)
		{
			_year += 1;
			_month = 1;
		}
	}
	return *this;
}

Date Date :: operator + (int day)
{
	Date temp = *this;
	temp += day;
	return temp;
}
//前置++
Date& Date :: operator++ ()
{
	*this += 1;
	return *this;
}
//后置++
Date Date :: operator++ (int)
{
	Date temp(*this);
	*this += 1;
	return temp;
}
