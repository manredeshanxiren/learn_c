#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
using namespace std;


int main()
{
	while (true)
	{
		int select = 0;//�����û�ѡ������ı���
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			AddPeo();
			break;
		case 2://��ʾ��ϵ��
			ScanCon();
			break;
		case 3://ɾ����ϵ��
			DelPeo();
			break;
		case 4://�޸���ϵ��
			ModifyPeo();
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}