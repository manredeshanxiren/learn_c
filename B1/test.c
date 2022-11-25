#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000

typedef struct tree {
	char data;
	struct tree* left;
	struct tree* right;
}Tree; //定义树的节点 

typedef struct {
	Tree* data[MAXSIZE];
	int top; //栈顶 
}Stack;


int deep = 0; //二叉树的高度 
int count = 0; //二叉树中叶子节点的个数 
int countK = 0;  //第k层的叶子节点个数 

void InitStack(Stack* p); //初始化栈 
void pushStack(Stack* p, Tree* c); //入栈
void popStack(Stack* p, Tree** c); //出栈
Tree* create(Tree* root); //扩展先序序列创建树 
//递归遍历 
void preOut(Tree* root); //先序遍历 
void midOut(Tree* root); //中序遍历
void rearOut(Tree* root); //后序遍历
//非递归遍历 
void preOut1(Tree* root, Stack* stack); //先序遍历 
void midOut1(Tree* root, Stack* stack); //中序遍历
void rearOut1(Tree* root, Stack* stack); //后序遍历
void rearOut2(Tree* root, Stack* stack); //后序遍历（简单版—先序改写）
void printTree(Tree* root, int h);  //输出树状图
void getCount(Tree* root);//统计二叉树中叶子结点的个数
void getHigh(Tree* root, int h);//计算二叉树的高度 
void getCountK(Tree* root, int h, int k);//计算指定的某一层k的叶子节点个数 

int main()
{
	Tree* root = (Tree*)malloc(sizeof(Tree));
	root = create(root); //扩展先序序列建立树 
	printf("树状输出：\n");
	printTree(root, 1); // 以树状形式打印输出 
	printf("\n");
	printf("递归先序:");
	preOut(root); //递归先序 
	printf("\n");
	printf("递归中序:");
	midOut(root); //递归中序 
	printf("\n");
	printf("递归后序:");
	rearOut(root); //递归后序 
	printf("\n");
	Stack stack;
	InitStack(&stack);
	printf("非递归先序:");
	preOut1(root, &stack); //非递归先序
	printf("\n");
	InitStack(&stack);
	printf("非递归中序:");
	midOut1(root, &stack); //非递归中序
	printf("\n");
	InitStack(&stack);
	printf("非递归后序:");
	rearOut1(root, &stack); //非递归后序
	printf("\n");
	InitStack(&stack);
	printf("非递归后序:");
	rearOut2(root, &stack); //非递归后序-简单版 
	printf("\n");
	getCount(root); //统计二叉树中叶子结点的个数
	printf("二叉树的叶子节点数量为%d\n", count);
	getHigh(root, 1); //计算二叉树的高度 
	printf("二叉树的高度为%d\n", deep);
	int k;
	printf("计算第k层的叶子节点个数，请输入k:");
	while (1) {
		scanf("%d", &k);
		if (k<1 || k>deep) {
			printf("没有这一层,请重新输入\n");
		}
		else {
			getCountK(root, 1, k); //计算指定的某一层k的叶子节点个数
			printf("第%d层的叶子节点个数为%d", k, countK);
			break;
		}
	}
}

void InitStack(Stack* p) //初始化栈 
{
	p->top = -1;
}

void pushStack(Stack* p, Tree* c) //入栈
{
	if (p->top + 1 >= MAXSIZE) return;
	p->data[++(p->top)] = c;
}

void popStack(Stack* p, Tree** c) //出栈
{
	if (p->top < 0) return;
	*c = p->data[(p->top)--];
}


Tree* create(Tree* root) { //扩展先序创建树  
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
//递归遍历 
void preOut(Tree* root) //先序遍历 
{
	if (!root) return;
	printf("%c", root->data);
	preOut(root->left);
	preOut(root->right);
}
void midOut(Tree* root) //中序遍历 
{
	if (!root) return;
	midOut(root->left);
	printf("%c", root->data);
	midOut(root->right);
}
void rearOut(Tree* root) //后序遍历 
{
	if (!root) return;
	rearOut(root->left);
	rearOut(root->right);
	printf("%c", root->data);
}
void printTree(Tree* root, int h) //输出树状图 
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
//非递归遍历 
void preOut1(Tree* root, Stack* stack) //先序遍历 
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
void midOut1(Tree* root, Stack* stack) //中序遍历 
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
void rearOut1(Tree* root, Stack* stack) //后序遍历 
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
void rearOut2(Tree* root, Stack* stack) //后序遍历（简单版—先序改写） 
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
void getCount(Tree* root)//统计二叉树中叶子结点的个数 
{
	if (!root) return;
	if (root->left == NULL && root->right == NULL) count++;
	getCount(root->left);
	getCount(root->right);
}
void getHigh(Tree* root, int h)//计算二叉树的高度 
{
	if (!root) return;
	if (deep < h) deep = h;
	getHigh(root->left, h + 1);
	getHigh(root->right, h + 1);
}
void getCountK(Tree* root, int h, int k)//计算指定的某一层k的叶子节点个数 
{
	if (!root) return;
	if (root->left == NULL && root->right == NULL && h == k) countK++;
	getCountK(root->left, h + 1, k);
	getCountK(root->right, h + 1, k);
}

