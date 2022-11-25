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


void Select(HuffmanTree* ht, int n, int* s1, int* s2);		// �����ڵ�
void CrtHuffmanTree(HuffmanTree* ht, int w[], int n);		// ������������
void CrtHuffmanCode(HuffmanTree* ht, int n, char str[]);		// ����������
void printHuffmanTree(HuffmanTree* ht, int n);				// ��ӡ��������


int main()
{
	int n;
	printf("�������ַ�������");
	scanf("%d", &n);
	getchar();
	printf("��������Щ�ַ���");
	for (int i = 0; i < n; i++) {
		scanf("%c", &str[i]);
		getchar();
	}
	printf("��������Щ�ַ���Ӧ��Ȩֵ��");
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	CrtHuffmanTree(huffman, w, n);
	CrtHuffmanCode(huffman, n, str);
	char s1[MAXSIZE];
	printf("������Ҫ������ַ�����");
	getchar();  
	scanf("%s", s1);
	printf("������Ϊ��");
	for (int i = 0; i < strlen(s1); i++) {
		printf("%s", strHuff[(int)s1[i]]);
	}
	return 0;
}
void Select(HuffmanTree* ht, int n, int* i1, int* i2) // ����������С�ڵ�
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
void CrtHuffmanTree(HuffmanTree* ht, int w[], int n) // ������������
{
	int i;
	int m = 2 * n - 1;

	for (i = 1; i <= n; i++)
	{
		//1��n�ŵ�Ԫ���Ҷ�ӽ�㣬��ʼ��
		ht[i].weight = w[i - 1];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = n + 1; i <= m; i++)
	{
		// n+1��m�ŵ�Ԫ��ŷ�Ҷ��㣬��ʼ��
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}

	printf("��ʼ�Ĺ�������Ϊ\n");
	printHuffmanTree(ht, 2 * n - 1);

	// ��ʼ����ϣ���ʼ������Ҷ���
	int s1, s2;
	for (i = n + 1; i <= m; i++)
	{
		// ������Ҷ��㣬����������
		Select(ht, i - 1, &s1, &s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[s1].parent = i;
		ht[s2].parent = i;
		ht[i].LChild = s1;
		ht[i].RChild = s2;
	}

	printf("������Ĺ�������Ϊ\n");
	printHuffmanTree(ht, 2 * n - 1);
}

void CrtHuffmanCode(HuffmanTree* ht, int n, char str[]) // ����������
{
	//��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ��(��n��)��Ӧ�Ĺ���������
	char* cd = (char*)malloc(n * sizeof(char));
	memset(cd, -1, n);
	for (int i = 1; i <= n; i++)
	{
		//��n��Ҷ�ӽ���Ӧ�Ĺ���������
		int start = n, c = i, p = ht[i].parent;
		while (p != 0) {
			--start;
			if (ht[p].LChild == c)			//���֧��0
				cd[start] = '0';
			else
				cd[start] = '1';			//�ҷ�֧��1
			c = p;							//���ϵ��� 
			p = ht[p].parent;
		}
		printf("%c�ı��룺", str[i - 1]);
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
void printHuffmanTree(HuffmanTree* ht, int n)  //��ӡ�������� 
{
	printf("���  weigh  parent LChild RChild\n");
	for (int i = 1; i <= n; i++)
		printf("%d\t%d\t%d\t%d\t%d\n", i, ht[i].weight, ht[i].parent, ht[i].LChild, ht[i].RChild);
	printf("\n");
}
