#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int n, s[200001], a[200001], l[200001], r[200001];
int top = 0;
int main2() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		while (top && a[i] <= a[s[top]])
			--top;
		//���ĿǰԪ��С��ջ��Ԫ�أ���ô��ջ��Ԫ�س�ջ 
		if (top)
			l[i] = s[top];
		//��¼i��ߵ�һ��С�ڵ�ǰ�߶ȵ�λ��s[top] 
		else
			l[i] = 0;
		//��������ڵĻ�����ô�ѵ�ǰλ�õ�ֵ��Ϊ0����Ϊ0����n+1�еĸ߶ȶ�Ϊ0. 
		s[++top] = i;
	}
	top = 0;
	for (int i = n; i; --i) {
		while (top && a[i] <= a[s[top]])
			--top;
		if (top)
			r[i] = s[top];
		else
			r[i] = n + 1;
		s[++top] = i;
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, 1ll * a[i] * (r[i] - l[i] - 1));
	}
	printf("%lld\n", ans);
	return 0;
}