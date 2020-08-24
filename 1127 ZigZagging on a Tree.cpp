#include<iostream>
#include<vector>
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
	for (int i = 0; i < n; i++) scanf("%d", &nodes[i].val);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	root = buildTree(0, 0, n);
	vector<int> now, nxt; bool flag = false;
	for (now.emplace_back(root); !now.empty(); flag = !flag) {
		for (const int& nodeId : now) {
			if (nodes[nodeId].lchild != -1) nxt.emplace_back(nodes[nodeId].lchild);
			if (nodes[nodeId].rchild != -1) nxt.emplace_back(nodes[nodeId].rchild);
		}
		if (flag) for (auto it = now.cbegin(); it != now.cend(); it++)
			printf("%d%c", nodes[*it].val, nodes[*it].val == nodes[now.back()].val && nxt.empty() ? '\n' : ' ');
		else for (auto it = now.crbegin(); it != now.crend(); it++)
			printf("%d%c", nodes[*it].val, nodes[*it].val == nodes[now.front()].val && nxt.empty() ? '\n' : ' ');
		now = nxt; nxt.clear();
	}
	return 0;
}