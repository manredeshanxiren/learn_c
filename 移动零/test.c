#include<stdio.h>
//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

//��ע�� �������ڲ���������������ԭ�ض�������в�����
#define N 2
int main()
{
	int nums[] = { 0, 0 };//ֻ�Ǹ���һ��{0�� 0}������
    int last = 0; //Ѱ����
    int fast = 0; //Ѱ�ҷ���
    //������ָ������
    //�ҵ���֮��ͣ����
    //���ÿ�ָ���ҷ���
    //�ҵ�����ͣ����
    //��������λ�õ�����(ͬʱ++����ָ��)
    //ֱ����ָ�뵽������β��
    while (fast < N && last < N)
    {
        while (*(nums + last) != 0  && last < N)
        {
            last++;
        }
        while (*(nums + fast) == 0 && fast < N)
        {
            fast++;
        }
        //������������
        if (last < N && fast < N)
        {
            int t = *(nums + last);
            *(nums + last) = *(nums + fast);
            *(nums + fast) = t;
            last++;
            fast++;
        }
    }
    return 0;
}