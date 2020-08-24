#include<iostream>
#include<queue>
using namespace std;
constexpr int MAXN = 30;
int post[MAXN];
struct Node {
	int val, lchild, rchild;
	Node() : lchild(-1), rchild(-1) {}
}nodes[MAXN];
int buildTree(const int& inL, const int& postL, const int& len) {
	for (int subLen = 0; subLen < len; subLen++) {
		if (nodes[inL + subLen].val != post[postL + len - 1]) continue;
		nodes[inL + subLen].lchild = buildTree(inL, postL, subLen);
		nodes[inL + subLen].rchild = buildTree(inL + subLen + 1, postL + subLen, len - subLen - 1);
		return inL + subLen;
	}
	return -1;
}
int main() {
	int n, root; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	for (int i = 0; i < n; i++) scanf("%d", &nodes[i].val);
	root = buildTree(0, 0, n);
	queue<int> q;
	for(q.push(root); !q.empty(); q.pop()) {
		const Node& node = nodes[q.front()];
		if(node.lchild != -1) q.push(node.lchild);
		if(node.rchild != -1) q.push(node.rchild);
		printf("%d%c", node.val, q.size() == 1 ? '\n' : ' ');
	}
	return 0;
}