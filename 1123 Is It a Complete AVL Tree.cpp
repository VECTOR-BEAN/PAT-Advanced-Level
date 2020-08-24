#include<iostream>
#include<queue>
using namespace std;
constexpr int MAXN = 20;
struct Node {
	int val, height, lchild, rchild;
} nodes[MAXN];
int getHeight(const int& id) { return id == -1 ? -1 : nodes[id].height; }
int getBalance(const int& id) { return getHeight(nodes[id].lchild) - getHeight(nodes[id].rchild); }
void updateHeight(const int& id) { nodes[id].height = max(getHeight(nodes[id].rchild), getHeight(nodes[id].lchild)) + 1; }
int rotateR(const int& root) {
	const int newRoot = nodes[root].lchild;
	nodes[root].lchild = nodes[newRoot].rchild;
	nodes[newRoot].rchild = root;
	updateHeight(root);
	updateHeight(newRoot);
	return newRoot;
}
int rotateL(const int& root) {
	const int newRoot = nodes[root].rchild;
	nodes[root].rchild = nodes[newRoot].lchild;
	nodes[newRoot].lchild = root;
	updateHeight(root);
	updateHeight(newRoot);
	return newRoot;
}
int insert(const int& newNode, int root) {
	if (nodes[newNode].val < nodes[root].val) {
		if(nodes[root].lchild == -1) nodes[root].lchild = newNode;
		else {
			nodes[root].lchild = insert(newNode, nodes[root].lchild);
			if (getBalance(root) == 2) { // left heavy
				if (getBalance(nodes[root].lchild) == 1) root = rotateR(root); // LL rotate
				else { // LR rotate
					nodes[root].lchild = rotateL(nodes[root].lchild);
					root = rotateR(root);
				}
			}
		}
	}
	else {
		if(nodes[root].rchild == -1) nodes[root].rchild = newNode;
		else {
			nodes[root].rchild = insert(newNode, nodes[root].rchild);
			if (getBalance(root) == -2) { // right heavy
				if (getBalance(nodes[root].rchild) == -1) root = rotateL(root); // RR rotate
				else { // RL rotate
					nodes[root].rchild = rotateR(nodes[root].rchild);
					root = rotateL(root);
				}
			}
		}
	}
	updateHeight(root);
	return root;
}
int main() {
	int n, root = 0, flag = 1; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nodes[i].val);
		nodes[i].height = 0;
		nodes[i].lchild = nodes[i].rchild = -1;
	}
	for (int i = 1; i < n; i++) root = insert(i, root);
	queue<int> q; // level order tranversal
	for (q.push(root); !q.empty(); q.pop()) {
		const Node& node = nodes[q.front()];
		if (node.lchild != -1) q.push(node.lchild);
		if (node.rchild != -1) q.push(node.rchild);
		printf("%d%c", node.val, q.size() == 1 ? '\n':' ');
		if (flag == 1) { 
			if (node.lchild != -1 && node.rchild != -1) continue;
			if (node.rchild == -1) flag = 0;
			else flag = -1;
		}
		else if (flag == 0 && (node.lchild != -1 || node.rchild != -1)) flag = -1;
	}
	printf("%s\n", flag != -1 ? "YES":"NO");
	return 0;
}