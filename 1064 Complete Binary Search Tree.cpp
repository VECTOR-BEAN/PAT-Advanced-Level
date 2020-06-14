#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1001;
int num[MAXN], ans[MAXN];
void inOrder(int root, int n, int& index) {
	if (root > n) return;
	inOrder(2 * root, n, index);
	ans[root] = num[index++];
	inOrder(2 * root + 1, n, index);
}
int main() {
	int n, index=0; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
  	sort(num, num+n); inOrder(1, n, index);
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i==n?'\n':' ');
	return 0;
}