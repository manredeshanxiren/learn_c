#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 10000
#define MAXNUM 999999

typedef struct {
	int weight;
	int parent;
	int LChild;
	int RChild;
}HuffmanTree;

HuffmanTree huffman[MAXSIZE];
char str[MAXSIZE];
int w[MAXSIZE];
char strHuff[200][MAXSIZE];


void Select(HuffmanTree* ht, int n, int* s1, int* s2);		// 搜索节点
void CrtHuffmanTree(HuffmanTree* ht, int w[], int n);		// 创建哈夫曼树
void CrtHuffmanCode(HuffmanTree* ht, int n, char str[]);		// 哈夫曼编码
void printHuffmanTree(HuffmanTree* ht, int n);				// 打印哈夫曼树


int main()
{
	int n;
	printf("请输入字符个数：");
	scanf("%d", &n);
	getchar();
	printf("请输入这些字符：");
	for (int i = 0; i < n; i++) {
		scanf("%c", &str[i]);
		getchar();
	}
	printf("请输入这些字符对应的权值：");
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	CrtHuffmanTree(huffman, w, n);
	CrtHuffmanCode(huffman, n, str);
	char s1[MAXSIZE];
	printf("请输入要编码的字符串：");
	getchar();  
	scanf("%s", s1);
	printf("编码结果为：");
	for (int i = 0; i < strlen(s1); i++) {
		printf("%s", strHuff[(int)s1[i]]);
	}
	return 0;
}
void Select(HuffmanTree* ht, int n, int* i1, int* i2) // 搜索两个最小节点
{
	int min1 = MAXNUM, min2 = MAXNUM;
	*i1 = 0;
	*i2 = 0;
	for (int i = 1; i <= n; i++) {
		if (ht[i].parent == 0) {
			if (ht[i].weight < min1) {
				min2 = min1;
				*i2 = *i1;
				min1 = ht[i].weight;
				*i1 = i;
			}
			else {
				if (ht[i].weight < min2) {
					min2 = ht[i].weight;
					*i2 = i;
				}
			}
		}
	}
}
void CrtHuffmanTree(HuffmanTree* ht, int w[], int n) // 创建哈夫曼树
{
	int i;
	int m = 2 * n - 1;

	for (i = 1; i <= n; i++)
	{
		//1至n号单元存放叶子结点，初始化
		ht[i].weight = w[i - 1];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = n + 1; i <= m; i++)
	{
		// n+1至m号单元存放非叶结点，初始化
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}

	printf("初始的哈夫曼树为\n");
	printHuffmanTree(ht, 2 * n - 1);

	// 初始化完毕，开始创建非叶结点
	int s1, s2;
	for (i = n + 1; i <= m; i++)
	{
		// 创建非叶结点，建哈夫曼树
		Select(ht, i - 1, &s1, &s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[s1].parent = i;
		ht[s2].parent = i;
		ht[i].LChild = s1;
		ht[i].RChild = s2;
	}

	printf("构建后的哈夫曼树为\n");
	printHuffmanTree(ht, 2 * n - 1);
}

void CrtHuffmanCode(HuffmanTree* ht, int n, char str[]) // 哈夫曼编码
{
	//从叶子结点到根，逆向求每个叶子结点(共n个)对应的哈夫曼编码
	char* cd = (char*)malloc(n * sizeof(char));
	memset(cd, -1, n);
	for (int i = 1; i <= n; i++)
	{
		//求n个叶子结点对应的哈夫曼编码
		int start = n, c = i, p = ht[i].parent;
		while (p != 0) {
			--start;
			if (ht[p].LChild == c)			//左分支标0
				cd[start] = '0';
			else
				cd[start] = '1';			//右分支标1
			c = p;							//向上倒推 
			p = ht[p].parent;
		}
		printf("%c的编码：", str[i - 1]);
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (cd[j] == '0' || cd[j] == '1') {
				printf("%c", cd[j]);
				strHuff[(int)str[i - 1]][cnt++] = cd[j];
			}
		}
		printf("\n");
		memset(cd, -1, n);
	}
}
void printHuffmanTree(HuffmanTree* ht, int n)  //打印哈夫曼树 
{
	printf("结点  weigh  parent LChild RChild\n");
	for (int i = 1; i <= n; i++)
		printf("%d\t%d\t%d\t%d\t%d\n", i, ht[i].weight, ht[i].parent, ht[i].LChild, ht[i].RChild);
	printf("\n");
}
