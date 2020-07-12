#include<iostream>
using namespace std;
constexpr int MAXN = 1000;
int maxDepth = 0, cnt[MAXN];
struct Node{
	int data, lchild, rchild;
} nodes[MAXN];
void DFS(const int& root, const int& depth) {
	if(root == -1) return;
	cnt[depth]++;
	if(depth > maxDepth) maxDepth = depth;
	DFS(nodes[root].lchild, depth + 1);
	DFS(nodes[root].rchild, depth + 1);
}
int main() {
	int n; scanf("%d", &n);
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
	DFS(0, 0);
	printf("%d + %d = %d\n", cnt[maxDepth], cnt[maxDepth-1], cnt[maxDepth] + cnt[maxDepth-1]);
	return 0;
}