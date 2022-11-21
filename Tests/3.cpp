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
		//如果目前元素小于栈顶元素，那么把栈顶元素出栈 
		if (top)
			l[i] = s[top];
		//记录i左边第一个小于当前高度的位置s[top] 
		else
			l[i] = 0;
		//如果不存在的话，那么把当前位置的值设为0，因为0，和n+1列的高度都为0. 
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