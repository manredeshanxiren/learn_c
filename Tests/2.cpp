#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int top, a[200001], b[200001], res[200001], n;
int main() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		while (top && a[b[top]] < a[i]) {
			res[b[top]] = i;
			top--;
		}
		b[++top] = i;
	}
	for (int i = 1; i <= top; i++) {
		res[b[i]] = 0;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
}