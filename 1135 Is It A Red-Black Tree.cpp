#include<iostream>
#include<queue>
using namespace std;
constexpr int MAXN = 30;
struct Node {
	int val, l, r;
	bool black() { return val >= 0; }
} nodes[MAXN];
void insert(const int& root, const int& index) {
	if (abs(nodes[index].val) <= abs(nodes[root].val)) {
		if (nodes[root].l == -1) nodes[root].l = index;
		else insert(nodes[root].l, index);
	}
	else {
		if (nodes[root].r == -1) nodes[root].r = index;
		else insert(nodes[root].r, index);
	}
}
int nBlackNodes(const int& root) {
	if (root == -1) return 1;
	const int l = nBlackNodes(nodes[root].l);
	const int r = nBlackNodes(nodes[root].r);
	return nodes[root].val < 0 ? max(l, r) : max(l, r) + 1;
}
int main() {
	int k; scanf("%d", &k);
	for (int i = 0, n, flag, root = 0; i < k && scanf("%d", &n); i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &nodes[j].val);
			nodes[j].l = nodes[j].r = -1;
		}
		for (int j = 1; j < n; j++) insert(root, j);
		queue<int> q; flag = nodes[root].val >= 0;
		for (q.push(root); !q.empty() && flag; q.pop()) {
			const Node& node = nodes[q.front()];
			if (node.val < 0) {
				if (node.l != -1) flag = flag && nodes[node.l].black();
				if (node.r != -1) flag = flag && nodes[node.r].black();
			}
			flag = flag && (nBlackNodes(node.l) == nBlackNodes(node.r));
			if (node.l != -1) q.push(node.l);
			if (node.r != -1) q.push(node.r);
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}