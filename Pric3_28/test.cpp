//#define _CRT_SECURE_NO_WARNINGS 1
//
////�������򷽷�
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	string* a = new string[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	int ds = 1, ls = 1;  //ds�ж��ֵ䣬ls�жϳ���
//	//�ֵ������ж�
//	for (int i = 1; i < n; i++)
//	{
//		if (a[i - 1] > a[i])		//ǰ��Ⱥ���󣬲�����
//		{
//			ds = 0;
//			break;
//		}
//	}
//	//���������ж�
//	for (int i = 1; i < n; i++)
//	{
//		if (a[i - 1].size() > a[i].size())  //ǰ��Ⱥ��泤��������
//		{
//			ls = 0;
//			break;
//		}
//	}
//
//	if (ds == 1 && ls == 0)								//�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically"
//		cout << "lexicographically" << endl;
//	if (ds == 0 && ls == 1)								//������ݳ������ж������ֵ����������"lengths",
//		cout << "lengths" << endl;
//	if (ds == 1 && ls == 1)								//������ַ�ʽ���������"both"���������"none"
//		cout << "both" << endl;
//	if (ds == 0 && ls == 0)
//		cout << "none" << endl;
//
//	return 0;
//}

////��С������
// ����һ
//#include<stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d %d", &a, &b);
//	int i = 1;
//	while ((a * i) % b != 0)
//	{
//		i++;
//	}
//	printf("%d\n", i * a);
//	return 0;
//}

//������
