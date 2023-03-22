#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;

class Person
{
public :
	void showInfo(Person* this)
	{
		cout << this->_name << this->_sex << ->_age << endl;
	}
public:
	int _name;
	int _age;
	int _sex;
};