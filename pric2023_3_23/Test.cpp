#define _CRT_SECURE_NO_WARNINGS 1
////�����ǹ�
//#include<iostream>
//using namespace std;
//int main()
//{
//    int arr[4] = { 0 };
//    double a, b1, b2, c;
//    for (int i = 0; i < 4; i++)
//    {
//        cin >> arr[i];
//    }
//    a = (arr[0] + arr[2]) * 1.0 / 2;
//    b1 = (arr[1] + arr[3]) * 1.0 / 2;
//    b2 = (arr[2] - arr[0]) * 1.0 / 2;
//    c = (arr[3] - arr[1]) * 1.0 / 2;
//    if (b1 != b2)
//    {
//        cout << "No" << endl;
//    }
//    else if ((a - (int)a) && (b1 - (int)b1) && (c - (int)c))
//    {
//        cout << "No" << endl;
//    }
//    else if (!((a >= 0) && (b1 >= 0) && (c >= 0)))
//    {
//        cout << "No" << endl;
//    }
//    else
//    {
//        cout << a << ' ' << b1 << ' ' << c << endl;
//    }
//    return 0;
//}

//����ת��
//#include<iostream>
//using namespace std;
//int main()
//{
//    int n = 0;//�洢��ת��������
//    int x = 0;//x����
//    int i = 0;//���ڼ���
//    int cut = 0;//0��ʾ����1��ʾ����
//    char ch[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
//    int arr[33] = { 0 };//��ʱ�洢ת���������
//    cin >> n >> x;
//    if (!(n >= 0))
//    {
//        cut = 1;
//    }
//    n = abs(n);
//    while (n >= x)
//    {
//        arr[i++] = n % x;
//        n /= x;
//    }
//    //δ���������
//    if (n != 0)
//    {
//        arr[i] = n;
//    }
//    if (cut == 1)
//    {
//        cout << '-';
//    }
//    for (int j = i; j >= 0; j--)
//    {
//        cout << ch[arr[j]];
//    }
//    return 0;
//}