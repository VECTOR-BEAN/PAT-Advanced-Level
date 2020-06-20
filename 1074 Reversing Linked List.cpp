#include<iostream>
using namespace std;
constexpr int MAXN = 100000;
struct Node {
	int addr, data, next;
} newNode, nodes[MAXN], ans[MAXN];
int main() {
	int addr, n, k; scanf("%d%d%d", &addr, &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &newNode.addr, &newNode.data, &newNode.next);
		nodes[newNode.addr] = newNode;
	}
	n = 0;
	for (int tAddr = addr; tAddr != -1; tAddr = nodes[tAddr].next) ans[n++] = nodes[tAddr];
	for (int i = 0; i + k - 1 < n; i += k) {
		for (int j = i + k - 1; j > i; j--) printf("%05d %d %05d\n", ans[j].addr, ans[j].data, ans[j-1].addr);
		if (i + k < n && i + 2*k - 1 < n) printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i+2*k-1].addr);
		else if(i + k < n && i + 2*k - 1 >= n) printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i+k].addr);
		else printf("%05d %d -1\n", ans[i].addr, ans[i].data);
	}
	for (int i = n - n % k; i < n; i++) {
		if (i < n - 1) printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i + 1].addr); 
		else printf("%05d %d -1\n", ans[i].addr, ans[i].data);
	}
	return 0;
}