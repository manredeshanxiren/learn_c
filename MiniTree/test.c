#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#define MAX 32767
typedef struct Matrix//定义结构体 
{
	int arcs[20][20];//结构体大小 
	int poinum;//顶点的数目 
	int edenum;//边的数目 
	char vex[20];//顶点的信息 

}Matrix;

typedef struct edge //定义边的结构体 
{
	int begin;//纪录边的两个结点 
	int end;
	int weight;
	int isfind;//纪录是否被使用到 
}Edge;

Edge edge[20];//定义边集数组 

int Location(Matrix* M, char a)//查找函数 
{
	for (int i = 0; i < M->poinum; i++) {
		if (M->vex[i] == a)
			return i;

	}
	return 0;
}

//查找v所在树的根节点 
int find(int* parent, int v)
{
	while (parent[v] > 0)
	{
		v = parent[v];//寻找双亲结点直至根节点 
	}
	return v;
}

void Sort(Matrix* M, int k)
{
	//使用冒泡排序 
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
	int parent[100] = { 0 };//纪录能否生成环路 - 数组纪录双亲结点的位置 
	int i, j, k = 0;
	int v1, v2;
	//将邻接矩阵转换为边集数组 
	for (i = 0; i < M->poinum - 1; i++)
	{
		for (j = i + 1; j < M->poinum; j++)
		{
			if (M->arcs[i][j] != MAX)
			{
				edge[k].begin = i;//将行下标放到begin里面 
				edge[k].end = j;//将列下标放到end里面 
				edge[k].weight = M->arcs[i][j];//权值赋 
				edge[k].isfind = 0;//判断边是否被使用的变量初始化为0 
				k++;//边集数组的下标 
			}
		}
	}
	Sort(M, k);//按权值升序排序 

	for (i = 0; i < M->edenum; i++)
	{
		v1 = find(parent, edge[i].begin);//查找begin的根节点 
		v2 = find(parent, edge[i].end);//查找end的根节点 

		if (v1 != v2)//判断根节点是否相同 
		{
			parent[v1] = v2;//v1的双亲结点为v2 - 标志着v2顶点加入到生成树集合里面 
			edge[i].isfind = 1;//改变是否被使用 - 改为已使用 
			num++;//变量num纪录加入生成树边的数目 
		}
		//优化：提前退出 
		printf("(%c,%c,%d,%d)", M->vex[edge[i].begin], M->vex[edge[i].end], edge[i].weight, edge[i].isfind);
		if (num == M->poinum - 1)return;//如果加入生成树的边数等于顶点数目-1，可以退出不再进行判断 
	}
}

int main()
{
	int i, j, k, weight;
	Matrix* M = (Matrix*)malloc(sizeof(Matrix));//申请邻接矩阵空间 
	char vex1, vex2;
	scanf("%d%d", &M->poinum, &M->edenum);
	getchar();
	for (i = 0; i < M->poinum; i++) {
		for (j = 0; j < M->poinum; j++) {
			M->arcs[i][j] = MAX;//邻接矩阵初始化 
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
		j = Location(M, vex1);//查找所在行下标 
		k = Location(M, vex2);//查找所在列下标 
		M->arcs[j][k] = weight;//保存权值 
		M->arcs[k][j] = M->arcs[j][k];//无向图 - 对称的 
	}

	kruskal(M);
}
