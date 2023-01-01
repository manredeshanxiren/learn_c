#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#define MAX 32767
typedef struct Matrix//����ṹ�� 
{
	int arcs[20][20];//�ṹ���С 
	int poinum;//�������Ŀ 
	int edenum;//�ߵ���Ŀ 
	char vex[20];//�������Ϣ 

}Matrix;

typedef struct edge //����ߵĽṹ�� 
{
	int begin;//��¼�ߵ�������� 
	int end;
	int weight;
	int isfind;//��¼�Ƿ�ʹ�õ� 
}Edge;

Edge edge[20];//����߼����� 

int Location(Matrix* M, char a)//���Һ��� 
{
	for (int i = 0; i < M->poinum; i++) {
		if (M->vex[i] == a)
			return i;

	}
	return 0;
}

//����v�������ĸ��ڵ� 
int find(int* parent, int v)
{
	while (parent[v] > 0)
	{
		v = parent[v];//Ѱ��˫�׽��ֱ�����ڵ� 
	}
	return v;
}

void Sort(Matrix* M, int k)
{
	//ʹ��ð������ 
	Edge tmp;
	int i, j;
	for (i = 0; i < k - 1; i++)
	{
		for (j = i + 1; j < k; j++)
		{
			if (edge[i].weight > edge[j].weight)
			{
				tmp = edge[i];
				edge[i] = edge[j];
				edge[j] = tmp;
			}
		}
	}
}


void kruskal(Matrix* M)
{
	int num = 0;
	int parent[100] = { 0 };//��¼�ܷ����ɻ�· - �����¼˫�׽���λ�� 
	int i, j, k = 0;
	int v1, v2;
	//���ڽӾ���ת��Ϊ�߼����� 
	for (i = 0; i < M->poinum - 1; i++)
	{
		for (j = i + 1; j < M->poinum; j++)
		{
			if (M->arcs[i][j] != MAX)
			{
				edge[k].begin = i;//�����±�ŵ�begin���� 
				edge[k].end = j;//�����±�ŵ�end���� 
				edge[k].weight = M->arcs[i][j];//Ȩֵ�� 
				edge[k].isfind = 0;//�жϱ��Ƿ�ʹ�õı�����ʼ��Ϊ0 
				k++;//�߼�������±� 
			}
		}
	}
	Sort(M, k);//��Ȩֵ�������� 

	for (i = 0; i < M->edenum; i++)
	{
		v1 = find(parent, edge[i].begin);//����begin�ĸ��ڵ� 
		v2 = find(parent, edge[i].end);//����end�ĸ��ڵ� 

		if (v1 != v2)//�жϸ��ڵ��Ƿ���ͬ 
		{
			parent[v1] = v2;//v1��˫�׽��Ϊv2 - ��־��v2������뵽�������������� 
			edge[i].isfind = 1;//�ı��Ƿ�ʹ�� - ��Ϊ��ʹ�� 
			num++;//����num��¼�����������ߵ���Ŀ 
		}
		//�Ż�����ǰ�˳� 
		printf("(%c,%c,%d,%d)", M->vex[edge[i].begin], M->vex[edge[i].end], edge[i].weight, edge[i].isfind);
		if (num == M->poinum - 1)return;//��������������ı������ڶ�����Ŀ-1�������˳����ٽ����ж� 
	}
}

int main()
{
	int i, j, k, weight;
	Matrix* M = (Matrix*)malloc(sizeof(Matrix));//�����ڽӾ���ռ� 
	char vex1, vex2;
	scanf("%d%d", &M->poinum, &M->edenum);
	getchar();
	for (i = 0; i < M->poinum; i++) {
		for (j = 0; j < M->poinum; j++) {
			M->arcs[i][j] = MAX;//�ڽӾ����ʼ�� 
		}
	}
	for (i = 0; i < M->poinum; i++)
	{
		scanf("%c", &M->vex[i]);
	}
	getchar();

	for (i = 0; i < M->edenum; i++)
	{
		scanf("(%c,%c,%d)", &vex1, &vex2, &weight);
		j = Location(M, vex1);//�����������±� 
		k = Location(M, vex2);//�����������±� 
		M->arcs[j][k] = weight;//����Ȩֵ 
		M->arcs[k][j] = M->arcs[j][k];//����ͼ - �ԳƵ� 
	}

	kruskal(M);
}
