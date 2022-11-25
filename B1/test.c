#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000

typedef struct tree {
	char data;
	struct tree* left;
	struct tree* right;
}Tree; //�������Ľڵ� 

typedef struct {
	Tree* data[MAXSIZE];
	int top; //ջ�� 
}Stack;


int deep = 0; //�������ĸ߶� 
int count = 0; //��������Ҷ�ӽڵ�ĸ��� 
int countK = 0;  //��k���Ҷ�ӽڵ���� 

void InitStack(Stack* p); //��ʼ��ջ 
void pushStack(Stack* p, Tree* c); //��ջ
void popStack(Stack* p, Tree** c); //��ջ
Tree* create(Tree* root); //��չ�������д����� 
//�ݹ���� 
void preOut(Tree* root); //������� 
void midOut(Tree* root); //�������
void rearOut(Tree* root); //�������
//�ǵݹ���� 
void preOut1(Tree* root, Stack* stack); //������� 
void midOut1(Tree* root, Stack* stack); //�������
void rearOut1(Tree* root, Stack* stack); //�������
void rearOut2(Tree* root, Stack* stack); //����������򵥰桪�����д��
void printTree(Tree* root, int h);  //�����״ͼ
void getCount(Tree* root);//ͳ�ƶ�������Ҷ�ӽ��ĸ���
void getHigh(Tree* root, int h);//����������ĸ߶� 
void getCountK(Tree* root, int h, int k);//����ָ����ĳһ��k��Ҷ�ӽڵ���� 

int main()
{
	Tree* root = (Tree*)malloc(sizeof(Tree));
	root = create(root); //��չ�������н����� 
	printf("��״�����\n");
	printTree(root, 1); // ����״��ʽ��ӡ��� 
	printf("\n");
	printf("�ݹ�����:");
	preOut(root); //�ݹ����� 
	printf("\n");
	printf("�ݹ�����:");
	midOut(root); //�ݹ����� 
	printf("\n");
	printf("�ݹ����:");
	rearOut(root); //�ݹ���� 
	printf("\n");
	Stack stack;
	InitStack(&stack);
	printf("�ǵݹ�����:");
	preOut1(root, &stack); //�ǵݹ�����
	printf("\n");
	InitStack(&stack);
	printf("�ǵݹ�����:");
	midOut1(root, &stack); //�ǵݹ�����
	printf("\n");
	InitStack(&stack);
	printf("�ǵݹ����:");
	rearOut1(root, &stack); //�ǵݹ����
	printf("\n");
	InitStack(&stack);
	printf("�ǵݹ����:");
	rearOut2(root, &stack); //�ǵݹ����-�򵥰� 
	printf("\n");
	getCount(root); //ͳ�ƶ�������Ҷ�ӽ��ĸ���
	printf("��������Ҷ�ӽڵ�����Ϊ%d\n", count);
	getHigh(root, 1); //����������ĸ߶� 
	printf("�������ĸ߶�Ϊ%d\n", deep);
	int k;
	printf("�����k���Ҷ�ӽڵ������������k:");
	while (1) {
		scanf("%d", &k);
		if (k<1 || k>deep) {
			printf("û����һ��,����������\n");
		}
		else {
			getCountK(root, 1, k); //����ָ����ĳһ��k��Ҷ�ӽڵ����
			printf("��%d���Ҷ�ӽڵ����Ϊ%d", k, countK);
			break;
		}
	}
}

void InitStack(Stack* p) //��ʼ��ջ 
{
	p->top = -1;
}

void pushStack(Stack* p, Tree* c) //��ջ
{
	if (p->top + 1 >= MAXSIZE) return;
	p->data[++(p->top)] = c;
}

void popStack(Stack* p, Tree** c) //��ջ
{
	if (p->top < 0) return;
	*c = p->data[(p->top)--];
}


Tree* create(Tree* root) { //��չ���򴴽���  
	char ch;
	ch = getchar();
	if (ch == '#') {
		return NULL;
	}
	else {
		root = (Tree*)malloc(sizeof(Tree));
		root->data = ch;
		root->left = create(root->left);
		root->right = create(root->right);
	}
	return root;
}
//�ݹ���� 
void preOut(Tree* root) //������� 
{
	if (!root) return;
	printf("%c", root->data);
	preOut(root->left);
	preOut(root->right);
}
void midOut(Tree* root) //������� 
{
	if (!root) return;
	midOut(root->left);
	printf("%c", root->data);
	midOut(root->right);
}
void rearOut(Tree* root) //������� 
{
	if (!root) return;
	rearOut(root->left);
	rearOut(root->right);
	printf("%c", root->data);
}
void printTree(Tree* root, int h) //�����״ͼ 
{
	if (root == NULL) {
		return;
	}
	printTree(root->right, h + 1);
	for (int i = 0; i < h; i++) {
		printf(" ");
	}
	printf("%c\n", root->data);
	printTree(root->left, h + 1);
}
//�ǵݹ���� 
void preOut1(Tree* root, Stack* stack) //������� 
{
	if (!root) return;
	Tree* temp;
	pushStack(stack, root);
	while (stack->top > -1) {
		popStack(stack, &temp);
		printf("%c", temp->data);
		if (temp->right) {
			pushStack(stack, temp->right);
		}
		if (temp->left) {
			pushStack(stack, temp->left);
		}

	}
}
void midOut1(Tree* root, Stack* stack) //������� 
{
	if (!root) return;
	Tree* temp = root;
	while (temp || stack->top > -1) {
		while (temp) {
			pushStack(stack, temp);
			temp = temp->left;
		}
		popStack(stack, &temp);
		printf("%c", temp->data);
		temp = temp->right;
	}
}
void rearOut1(Tree* root, Stack* stack) //������� 
{
	if (!root) return;
	Tree* temp = root;
	Tree* visted = NULL;
	while (temp || stack->top > -1) {
		while (temp) {
			pushStack(stack, temp);
			temp = temp->left;
		}
		temp = stack->data[stack->top];
		if (temp->right == NULL || temp->right == visted) {
			printf("%c", temp->data);
			stack->top--;
			visted = temp;
			temp = NULL;
		}
		else {
			temp = temp->right;
		}
	}
}
void rearOut2(Tree* root, Stack* stack) //����������򵥰桪�����д�� 
{
	if (!root) return;
	Tree* temp;
	char data[MAXSIZE];
	int cnt = 0;
	pushStack(stack, root);
	while (stack->top > -1) {
		popStack(stack, &temp);
		data[cnt++] = temp->data;
		if (temp->left) {
			pushStack(stack, temp->left);
		}
		if (temp->right) {
			pushStack(stack, temp->right);
		}
	}
	for (int i = cnt - 1; i >= 0; i--) {
		printf("%c", data[i]);
	}
}
void getCount(Tree* root)//ͳ�ƶ�������Ҷ�ӽ��ĸ��� 
{
	if (!root) return;
	if (root->left == NULL && root->right == NULL) count++;
	getCount(root->left);
	getCount(root->right);
}
void getHigh(Tree* root, int h)//����������ĸ߶� 
{
	if (!root) return;
	if (deep < h) deep = h;
	getHigh(root->left, h + 1);
	getHigh(root->right, h + 1);
}
void getCountK(Tree* root, int h, int k)//����ָ����ĳһ��k��Ҷ�ӽڵ���� 
{
	if (!root) return;
	if (root->left == NULL && root->right == NULL && h == k) countK++;
	getCountK(root->left, h + 1, k);
	getCountK(root->right, h + 1, k);
}

