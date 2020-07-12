#include<iostream>
#include<queue>
using namespace std;
constexpr int MAXN = 1000;
int cnt[MAXN];
struct Node{
	int data, lchild, rchild;
} nodes[MAXN];
void BFS(const int& root, int& depth) {
	queue<int> q; depth = 0;
	for(q.push(root); !q.empty(); depth++) {
		cnt[depth] = q.size();
		for(int i = 0; i < cnt[depth]; i++, q.pop()) {
			const Node& node = nodes[q.front()];
			if(node.lchild != -1) q.push(node.lchild);
			if(node.rchild != -1) q.push(node.rchild);
		}
	}
	depth--;
}
int main() {
	int n, maxDepth; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &nodes[i].data);
		nodes[i].lchild = nodes[i].rchild = -1;
	}
	for(int i = 1; i < n; i++) {
		int root = 0;
		while(true) {
			if(nodes[i].data <= nodes[root].data) {
				if(nodes[root].lchild == -1) {
					nodes[root].lchild = i;
					break;
				}
				else root = nodes[root].lchild;
			}
			else{
				if(nodes[root].rchild == -1) {
					nodes[root].rchild = i;
					break;
				}
				else root = nodes[root].rchild;
			}
		}
	}
	BFS(0, maxDepth);
	printf("%d + %d = %d\n", cnt[maxDepth], cnt[maxDepth-1], cnt[maxDepth] + cnt[maxDepth-1]);
	return 0;
}