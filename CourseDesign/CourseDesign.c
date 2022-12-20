#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
//�߱���
typedef struct node
{
    int pos;
    int weight;
    struct node* next;
} edgnode;

//�������
typedef struct
{
    int in;
    int ver;
    edgnode* fp; //ָ��߽���ָ��
} vernode;

typedef struct
{
    int numver, numdeg;
    vernode ver[100];//���������
} map;

int findver(map* G, int v, int n)//���Ҷ����ڶ���������е�λ��
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
    printf("���붥�����ͱ�����\n");
    scanf("%d%d", &G->numver, &G->numdeg);
    printf("���������\n");
    for (i = 0; i < G->numver; i++)
    {
        scanf("%d", &G->ver[i].ver);
        G->ver[i].in = 0;
        G->ver[i].fp = NULL;
    }
    printf("�����߱�\n");
    for (k = 0; k < G->numdeg; k++)
    {
        //        printf("�������%d���ߵ�����յ��Ȩֵ��\n", k + 1);
        scanf("%d %d %d", &i, &j, &w);
        i = findver(G, i, G->numver);
        j = findver(G, j, G->numver);
        p = (edgnode*)malloc(sizeof(edgnode));
        p->weight = w;
        p->pos = j;                                 //ͷ�巨��������
        p->next = G->ver[i].fp;
        G->ver[i].fp = p;
    }
}
int toposort(map* G, int etv[], int stack1[])         //��������
{
    int i, gettop, top = 0, count = 0, top1 = 0;
    edgnode* p;
    int* stack = (int*)malloc(sizeof(int) * (G->numver)); //������Ϊ0�Ľ���������е��±�
    for (i = 0; i < G->numver; i++)
    {
        etv[i] = 0;                             //��ʼ���¼������緢��ʱ������
    }
    for (i = 0; i < G->numver; i++)
    {                                           //����ÿ����������
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
            stack[++top] = i;                 //���Ϊ0����������
        }
    }
    printf("��������Ϊ��");
    while (top != 0)
    {
        gettop = stack[top--];
        printf("%d", G->ver[gettop].ver);            //��ӡ���Ϊ0�Ķ���
        count++;
        stack1[++top1] = gettop;                    //�������Ķ�����Ŵ�����������������
        for (p = G->ver[gettop].fp; p != NULL; p = p->next)
        {                                            //�����ö��������
            if (!(--(G->ver[p->pos].in)))            //��ؽ����ȼ�һ�����Ϊ0����������
            {
                stack[++top] = p->pos;
                if (etv[gettop] + p->weight > etv[p->pos])  //����ÿ���¼������緢��ʱ��
                    etv[p->pos] = etv[gettop] + p->weight;
            }
        }
    }
    if (G->numver > count)
        printf("��ͼ���ڻ�");
    return top1;
}
void criticalpath(map* G, int etv[], int stack1[])
{
    edgnode* p;
    int i, j, k, gettop, early, late;
    int top1 = toposort(G, etv, stack1);
    int* ltv = (int*)malloc(sizeof(int) * (G->numver)); //�¼�������ʱ������
    for (i = 0; i < G->numver; i++)
    {
        ltv[i] = etv[G->numver - 1];                    //��ʼ���¼�������ʱ��
    }
    while (top1 != 0)
    {
        gettop = stack1[top1--];
        for (p = G->ver[gettop].fp; p != NULL; p = p->next)
        {
            if (ltv[p->pos] - p->weight < ltv[gettop])
            {
                ltv[gettop] = ltv[p->pos] - p->weight;//�����¼���������ʱ��
            }
        }
    }
    printf("\n�ؼ�·��Ϊ��\n");
    for (j = 0; j < G->numver; j++)
    {
        for (p = G->ver[j].fp; p != NULL; p = p->next)
        {
            early = etv[j];                             //������翪ʼʱ��
            late = ltv[p->pos] - p->weight;             //�������ʼʱ��
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
