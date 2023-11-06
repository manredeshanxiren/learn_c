#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

using namespace std;

namespace xu
{
	void showMenu()
	{
		cout << "************************" << endl;
		cout << "***** 1,添加联系人 *****" << endl;
		cout << "***** 2,显示联系人 *****" << endl;
		cout << "***** 3,删除联系人 *****" << endl;
		cout << "***** 4,修改联系人 *****" << endl;
		cout << "***** 0,退出通讯录 *****" << endl;
		cout << "************************" << endl;
	}


	//添加联系人函数
	void AddPeo()
	{
		cout << "添加联系人成功" << endl;
	}


	//查看联系人
	void ScanCon()
	{
		cout << "查看联系人成功" << endl;
	}


	//修改联系人
	void ModifyPeo()
	{
		cout << "修改联系人成功" << endl;
	}

	//删除联系人
	void DelPeo()
	{
		cout << "删除联系人成功" << endl;
	}

}