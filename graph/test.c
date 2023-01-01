#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXVEX 20
typedef struct SqStack {
	int vex[MAXVEX];
	int front;
	int rear;
}SqQueue;
typedef struct
{
	int arcs[MAXVEX][MAXVEX];
	int visited[MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjMatrix;
void Create(AdjMatrix* G) {
	int i, j, k, vex1, vex2;
	char Vex1, Vex2;
	//	printf("请输入有向网中的顶点数和边数:\n");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	for (i = 1; i <= G->vexnum; i++) {
		for (j = 1; j <= G->vexnum; j++) {
			G->arcs[i][j] = 0;
		}
	}
	getchar();
	//	printf("请输入有向图中%d个顶点:\n",G->vexnum);
	for (i = 1; i <= G->vexnum; i++) {
		//		printf("No.%d个顶点：",i);
		scanf("%c", &G->vex[i]);
	}
	getchar();
	//	printf("请输入有向图的%d条边",G->arcnum);
	for (k = 0; k < G->arcnum; k++) {
		//		printf("\nNo.%d条边:\n	顶点",k+1);
		scanf("%c", &Vex1);
		vex1 = Vex1 - 64;
		//		printf("<--->顶点");
		scanf("%c", &Vex2);
		vex2 = Vex2 - 64;
		getchar();
		//		printf("%d %d\n",vex1,vex2);
		G->arcs[vex1][vex2] = 1;
	}
}
/*初始化图的遍历数组*/
void initialise(AdjMatrix* G) {
	for (int i = 1; i <= G->vexnum; i++) {
		G->visited[i] = 0;
	}
}
/*深度优先*/
void DFS(AdjMatrix* G, int Vo) {
	/*类似于先序遍历*/
	printf("%c", G->vex[Vo]);
	G->visited[Vo] = 1;
	for (int i = 1; i <= G->vexnum; i++) {
		if (!G->visited[i] && G->arcs[Vo][i] == 1) {
			DFS(G, i);
		}
	}
}
int FirstAdj(AdjMatrix* G, int Vo) {
	for (int i = 1; i <= G->vexnum; i++) {
		if (G->arcs[Vo][i] == 1 && G->visited[i] != 1) {
			return i;
		}
	}
	return -1;
}
int NextAdj(AdjMatrix* G, int Vo, int w) {
	for (int i = w + 1; i <= G->vexnum; i++) {
		if (G->arcs[Vo][i] == 1 && G->visited[i] != 1) {
			return i;
		}
	}
	return -1;
}
/*广度优先*/
void BFS(AdjMatrix* G, int Vo) {
	/*类似于层次遍历*/
	printf("%c", G->vex[Vo]);
	G->visited[Vo] = 1;
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	Q->front = 0;
	Q->rear = 0;
	Q->front++;
	Q->vex[Q->front] = Vo;
	while (Q->front - Q->rear != 0) {
		Vo = Q->vex[Q->front];
		Q->rear++;
		int w = FirstAdj(G, Vo);
		//		printf("%d",w);
		while (w != -1) {
			if (!G->visited[w]) {
				printf("%c", G->vex[w]);
				G->visited[w] = 1;
				Q->front++;
				Q->vex[Q->front] = w;
			}
			w = NextAdj(G, Vo, w);
			//			printf("%d",w);
		}
	}
}
int main(void) {
	int i, j;
	AdjMatrix* G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	Create(G);
	int in[MAXVEX];
	int on[MAXVEX];
	for (i = 1; i <= G->vexnum; i++) {
		int count = 0;
		for (j = 1; j <= G->vexnum; j++) {
			//printf("%d ",G->arcs[i][j]);
			if (G->arcs[i][j] == 1) {
				count++;
			}
		}
		on[i] = count;
	}
	for (i = 1; i <= G->vexnum; i++) {
		int count = 0;
		for (j = 1; j <= G->vexnum; j++) {
			//printf("%d ",G->arcs[i][j]);
			if (G->arcs[j][i] == 1) {
				count++;
			}
		}
		in[i] = count;
	}
	//临界矩阵存储结果
	printf("临界矩阵存储结果:\n  ");
	for (i = 1; i <= G->vexnum; i++) {
		printf("%c ", G->vex[i]);
	}
	printf("\n");
	for (int i = 1; i <= G->vexnum; i++) 
	{
		printf("%c ", G->vex[i]);
		for (int j = 1; j <= G->vexnum; j++) 
		{
			printf("%d ", G->arcs[i][j]);
		}
		printf("\n");
	}
	//邻接表存储结果



	printf("出度和入度:\n");
	printf("顶点 出度 入度\n");
	for (i = 1; i <= G->vexnum; i++) {
		printf("  %c   %d   %d\n", G->vex[i], on[i], in[i]);
	}
	//深度优先遍历
	printf("深度优先遍历:\n");
	initialise(G);
	DFS(G, 1);
	printf("\n");
	//广度优先遍历
	printf("广度优先遍历:\n");
	initialise(G);
	BFS(G, 1);
	return 0;
}
