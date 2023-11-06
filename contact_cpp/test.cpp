#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
using namespace std;


int main()
{
	while (true)
	{
		int select = 0;//创建用户选择输入的变量
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			AddPeo();
			break;
		case 2://显示联系人
			ScanCon();
			break;
		case 3://删除联系人
			DelPeo();
			break;
		case 4://修改联系人
			ModifyPeo();
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}