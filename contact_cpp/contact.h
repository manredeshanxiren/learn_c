#pragma once

#define MAXSIZE 15

#include<iostream>
#include<string>

//�˵�
void showMenu();

//�����ϵ�˺���
void AddPeo();

//�鿴��ϵ��
void ScanCon();

//�޸���ϵ��
void ModifyPeo();

//ɾ����ϵ��
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

