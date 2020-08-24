#include<iostream>
#include<queue>
using namespace std;
typedef struct Node {
	int val, height;
	Node* lchild, * rchild;
	Node() = default;
	Node(const int& _val) : val(_val), height(0), lchild(NULL), rchild(NULL) {}
} *pNode;
int getHeight(const pNode& node) { return node != NULL ? node->height : -1; }
int getBalance(const pNode& node) { return getHeight(node->lchild) - getHeight(node->rchild); }
void updateHeight(const pNode& node) { node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1; }
pNode rotateR(const pNode& root) {
	const pNode newRoot = root->lchild;
	root->lchild = newRoot->rchild;
	newRoot->rchild = root;
	updateHeight(root);
	updateHeight(newRoot);
	return newRoot;
}
pNode rotateL(const pNode& root) {
	const pNode newRoot = root->rchild;
	root->rchild = newRoot->lchild;
	newRoot->lchild = root;
	updateHeight(root);
	updateHeight(newRoot);
	return newRoot;
}
pNode insert(const int& val, pNode root) {
	if (root == NULL) root = new Node(val);
	else if (val < root->val) {
		root->lchild = insert(val, root->lchild);
		if (getBalance(root) == 2) {
			if (getBalance(root->lchild) == 1) root = rotateR(root);
			else {
				root->lchild = rotateL(root->lchild);
				root = rotateR(root);
			}
		}
	}
	else {
		root->rchild = insert(val, root->rchild);
		if (getBalance(root) == -2) {
			if (getBalance(root->rchild) == -1) root = rotateL(root);
			else {
				root->rchild = rotateR(root->rchild);
				root = rotateL(root);
			}
		}
	}
	updateHeight(root);
	return root;
}
int main() {
	int n, flag = 1; pNode root = NULL;
	scanf("%d", &n);
	for (int i = 0, val; i < n; i++) {
		scanf("%d", &val);
		root = insert(val, root);
	}
	queue<pNode> q;
	for (q.push(root); !q.empty(); q.pop()) {
		const Node& node = *q.front();
		if (node.lchild != NULL) q.push(node.lchild);
		if (node.rchild != NULL) q.push(node.rchild);
		printf("%d%c", node.val, q.size() == 1 ? '\n' : ' ');
		if (flag == 1) {
			if (node.lchild != NULL && node.rchild != NULL) continue;
			if (node.rchild == NULL) flag = 0;
			else flag = -1;
		}
		else if (flag == 0 && (node.lchild != NULL || node.rchild != NULL)) flag = -1;
	}
	printf("%s\n", flag != -1 ? "YES":"NO");
	return 0;
}