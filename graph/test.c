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
	//	printf("�������������еĶ������ͱ���:\n");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	for (i = 1; i <= G->vexnum; i++) {
		for (j = 1; j <= G->vexnum; j++) {
			G->arcs[i][j] = 0;
		}
	}
	getchar();
	//	printf("����������ͼ��%d������:\n",G->vexnum);
	for (i = 1; i <= G->vexnum; i++) {
		//		printf("No.%d�����㣺",i);
		scanf("%c", &G->vex[i]);
	}
	getchar();
	//	printf("����������ͼ��%d����",G->arcnum);
	for (k = 0; k < G->arcnum; k++) {
		//		printf("\nNo.%d����:\n	����",k+1);
		scanf("%c", &Vex1);
		vex1 = Vex1 - 64;
		//		printf("<--->����");
		scanf("%c", &Vex2);
		vex2 = Vex2 - 64;
		getchar();
		//		printf("%d %d\n",vex1,vex2);
		G->arcs[vex1][vex2] = 1;
	}
}
/*��ʼ��ͼ�ı�������*/
void initialise(AdjMatrix* G) {
	for (int i = 1; i <= G->vexnum; i++) {
		G->visited[i] = 0;
	}
}
/*�������*/
void DFS(AdjMatrix* G, int Vo) {
	/*�������������*/
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
/*�������*/
void BFS(AdjMatrix* G, int Vo) {
	/*�����ڲ�α���*/
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
	//�ٽ����洢���
	printf("�ٽ����洢���:\n  ");
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
	//�ڽӱ�洢���



	printf("���Ⱥ����:\n");
	printf("���� ���� ���\n");
	for (i = 1; i <= G->vexnum; i++) {
		printf("  %c   %d   %d\n", G->vex[i], on[i], in[i]);
	}
	//������ȱ���
	printf("������ȱ���:\n");
	initialise(G);
	DFS(G, 1);
	printf("\n");
	//������ȱ���
	printf("������ȱ���:\n");
	initialise(G);
	BFS(G, 1);
	return 0;
}
