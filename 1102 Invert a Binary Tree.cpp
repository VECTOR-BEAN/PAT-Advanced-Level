#include<iostream>
#include<queue>
#include<stack>
using namespace std;
constexpr int MAXN = 10;
bool notRoot[MAXN];
struct Node{
	int lchild, rchild;
} nodes[MAXN];
int main() {
	int n, root; char a, b; scanf("%d%*c", &n);
	for(int i = 0; i < n; i++) {
		scanf("%c%*c%c%*c", &a, &b);
		Node& node = nodes[i];
		node.lchild = isdigit(a) ? a - '0' : -1;
		if(node.lchild != -1) notRoot[node.lchild] = true;
		node.rchild = isdigit(b) ? b - '0' : -1;
		if(node.rchild != -1) notRoot[node.rchild] = true;
	}
	for(root = 0; root < n && notRoot[root]; root++);
	if(n == root) return 0;
	queue<int> q; // level order traversal
	for(q.push(root); !q.empty(); q.pop()) {
		const Node& node = nodes[q.front()];
		if(node.rchild != -1) q.push(node.rchild);
		if(node.lchild != -1) q.push(node.lchild);
		printf("%d%c", q.front(), q.size() == 1 ? '\n':' ');
	}
	stack<int> s; // inorder traversal
	for(int cur = root; cur != -1 || !s.empty(); s.pop()) {
		if(cur != -1) {
			s.push(cur);
			while(nodes[s.top()].rchild != -1) s.push(nodes[s.top()].rchild);
		}
		cur = nodes[s.top()].lchild;
		printf("%d%c", s.top(), (cur == -1 && s.size() == 1) ? '\n' : ' ');
	}
	return 0;
}