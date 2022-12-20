#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
//边表结点
typedef struct node
{
    int pos;
    int weight;
    struct node* next;
} edgnode;

//顶点表结点
typedef struct
{
    int in;
    int ver;
    edgnode* fp; //指向边结点的指针
} vernode;

typedef struct
{
    int numver, numdeg;
    vernode ver[100];//顶点表数组
} map;

int findver(map* G, int v, int n)//查找顶点在顶点表数组中的位置
{
    for (int i = 0; i < n; i++)
    {
        if (G->ver[i].ver == v)
        {
            return i;
        }
    }
}

void creatmap(map* G)
{
    int i, j, k, w;
    edgnode* p;
    printf("输入顶点数和边数：\n");
    scanf("%d%d", &G->numver, &G->numdeg);
    printf("创建顶点表：\n");
    for (i = 0; i < G->numver; i++)
    {
        scanf("%d", &G->ver[i].ver);
        G->ver[i].in = 0;
        G->ver[i].fp = NULL;
    }
    printf("创建边表：\n");
    for (k = 0; k < G->numdeg; k++)
    {
        //        printf("请输入第%d条边的起点终点和权值：\n", k + 1);
        scanf("%d %d %d", &i, &j, &w);
        i = findver(G, i, G->numver);
        j = findver(G, j, G->numver);
        p = (edgnode*)malloc(sizeof(edgnode));
        p->weight = w;
        p->pos = j;                                 //头插法建立链表
        p->next = G->ver[i].fp;
        G->ver[i].fp = p;
    }
}
int toposort(map* G, int etv[], int stack1[])         //拓扑排序
{
    int i, gettop, top = 0, count = 0, top1 = 0;
    edgnode* p;
    int* stack = (int*)malloc(sizeof(int) * (G->numver)); //存放入度为0的结点在数组中的下标
    for (i = 0; i < G->numver; i++)
    {
        etv[i] = 0;                             //初始化事件的最早发生时间数组
    }
    for (i = 0; i < G->numver; i++)
    {                                           //查找每个顶点的入度
        p = G->ver[i].fp;
        while (p)
        {
            G->ver[p->pos].in++;
            p = p->next;
        }
    }
    for (i = 0; i < G->numver; i++)
    {
        if (G->ver[i].in == 0)
        {
            stack[++top] = i;                 //入度为0放入数组中
        }
    }
    printf("拓扑排序为：");
    while (top != 0)
    {
        gettop = stack[top--];
        printf("%d", G->ver[gettop].ver);            //打印入度为0的顶点
        count++;
        stack1[++top1] = gettop;                    //将弹出的顶点序号存入拓扑序列数组中
        for (p = G->ver[gettop].fp; p != NULL; p = p->next)
        {                                            //遍历该顶点的链表
            if (!(--(G->ver[p->pos].in)))            //相关结点入度减一，如果为0存入数组中
            {
                stack[++top] = p->pos;
                if (etv[gettop] + p->weight > etv[p->pos])  //计算每个事件的最早发生时间
                    etv[p->pos] = etv[gettop] + p->weight;
            }
        }
    }
    if (G->numver > count)
        printf("该图存在环");
    return top1;
}
void criticalpath(map* G, int etv[], int stack1[])
{
    edgnode* p;
    int i, j, k, gettop, early, late;
    int top1 = toposort(G, etv, stack1);
    int* ltv = (int*)malloc(sizeof(int) * (G->numver)); //事件最晚发生时间数组
    for (i = 0; i < G->numver; i++)
    {
        ltv[i] = etv[G->numver - 1];                    //初始化事件最晚发生时间
    }
    while (top1 != 0)
    {
        gettop = stack1[top1--];
        for (p = G->ver[gettop].fp; p != NULL; p = p->next)
        {
            if (ltv[p->pos] - p->weight < ltv[gettop])
            {
                ltv[gettop] = ltv[p->pos] - p->weight;//计算事件的最晚发生时间
            }
        }
    }
    printf("\n关键路径为：\n");
    for (j = 0; j < G->numver; j++)
    {
        for (p = G->ver[j].fp; p != NULL; p = p->next)
        {
            early = etv[j];                             //活动的最早开始时间
            late = ltv[p->pos] - p->weight;             //活动的最晚开始时间
            if (early == late)
            {
                printf("<V%d--V%d> \n", G->ver[j].ver, G->ver[p->pos].ver);
            }
        }
    }
}

void main()
{
    map G = {0,0};
    int* etv = (int*)malloc(sizeof(int) * (G.numver));
    int* stack1 = (int*)malloc(sizeof(int) * (G.numver));
    creatmap(&G);
    criticalpath(&G, etv, stack1);
}
