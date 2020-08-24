#include<iostream>
constexpr int MAXN = 21;
bool notRoot[MAXN];
struct Node{
	char str[11];
	int lchild, rchild;
	bool isLeaf() const {return lchild == -1 && rchild == -1; }
} nodes[MAXN];
void inorder(const int& root) {
	if(root == -1) return;
	else if(nodes[root].isLeaf()) printf("%s", nodes[root].str);
	else {
		putchar('('); inorder(nodes[root].lchild);
		printf("%s", nodes[root].str);
		inorder(nodes[root].rchild); putchar(')');
	}
}
int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s%d%d", nodes[i].str, &nodes[i].lchild, &nodes[i].rchild);
		if(nodes[i].lchild != -1) notRoot[nodes[i].lchild] = true;
		if(nodes[i].rchild != -1) notRoot[nodes[i].rchild] = true;
	}
	for(int root = 1; root <= n; root++) {
		if(notRoot[root]) continue;
		inorder(nodes[root].lchild);
		printf("%s", nodes[root].str);
		inorder(nodes[root].rchild);
		putchar('\n'); break;
	}
	return 0;
}