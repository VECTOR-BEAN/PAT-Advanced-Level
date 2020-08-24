#include<iostream>
constexpr int MAXN = 1001;
int vals[MAXN];
void postOrder(const int& root, const int& n) {
	if(root > n) return;
	postOrder(2 * root, n);
	postOrder(2 * root + 1, n);
	printf("%d%c", vals[root], root == 1 ? '\n' : ' ');
}
int main() {
	int m, n; scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j <= n; ++j) scanf("%d", &vals[j]);
		bool flag1 = (vals[1] >= vals[2]), flag2 = flag1;
		for (int j = 2; j <= n && flag1 == flag2; ++j) {
			flag2 = vals[j / 2] >= vals[j];
		}
		if (flag1 != flag2) printf("Not Heap\n");
		else printf("%s\n", flag1 ? "Max Heap" : "Min Heap");
		postOrder(1, n);
	}
	return 0;
}