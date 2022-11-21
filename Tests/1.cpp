#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int m, x;
int top;
int nl[100001];
char a[11];
int main() {

	scanf_s("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf_s("%s", a);
		if (a[1] == 'u')
		{
			scanf_s("%d", &x);
			nl[++top] = x;
		}
		else if (a[0] == 'p') {
			--top;
		}
		else
			printf("%d", nl[top]);
	}

	return 0;
}