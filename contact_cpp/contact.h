#pragma once

#define MAXSIZE 15

#include<iostream>
#include<string>

//菜单
void showMenu();

//添加联系人函数
void AddPeo();

//查看联系人
void ScanCon();

//修改联系人
void ModifyPeo();

//删除联系人
void DelPeo();

class peo
{
public:
	peo()
	{
		_name = new string();
		_number = new string();
		_type = new string();
		_email = new string();
	}
	~peo()
	{
		delete _name;
		delete _number;
		delete _type;
		delete _email;
	}
private:
	string* _name;
	string* _number;
	string* _type;
	string* _email;
};

