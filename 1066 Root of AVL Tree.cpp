#include<iostream>
using namespace std;
typedef struct Node {
	int value, height;
	Node* lchild, * rchild;
} *pNode;
int getHeight(pNode pnode) { return pnode == NULL ? 0 : pnode->height; }
int getBF(pNode pnode) { return getHeight(pnode->lchild) - getHeight(pnode->rchild); }
void updateHeight(pNode pnode) { pnode->height = max(getHeight(pnode->lchild), getHeight(pnode->rchild)) + 1; }
pNode newNode(int value) {
	pNode node = new Node;
	node->value = value; node->height = 1; node->lchild = node->rchild = NULL;
	return node;
}
void rotateLeft(pNode& root) {
	pNode temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	root = temp;
	updateHeight(root->lchild);
	updateHeight(root);
}
void rotateRight(pNode& root) {
	pNode temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	root = temp;
	updateHeight(root->rchild);
	updateHeight(root);
}
void insert(pNode& root, int value) {
	if (root == NULL) root = newNode(value);
	else if (value < root->value) {
		insert(root->lchild, value);
		updateHeight(root);
		if (getBF(root) == 2) {
			if (getBF(root->lchild) == 1) rotateRight(root);
			else if (getBF(root->lchild) == -1) { rotateLeft(root->lchild); rotateRight(root); }
		}
	}
	else {
		insert(root->rchild, value);
		updateHeight(root);
		if (getBF(root) == -2) {
			if (getBF(root->rchild) == -1) rotateLeft(root);
			else if (getBF(root->rchild) == 1) { rotateRight(root->rchild); rotateLeft(root); }
		}
	}
}
int main() {
	int n; scanf("%d", &n);
	pNode root = NULL; 
	for (int i = 0, value; i < n; i++) {
		scanf("%d", &value);
		insert(root, value);
	}
	if (root == NULL) printf("NULL");
	else printf("%d\n", root->value);
	return 0;
}