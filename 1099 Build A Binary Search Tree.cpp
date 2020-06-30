#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100;
struct Node{
	int data, lchild, rchild;
} nodes[MAXN];
int n, idx = 0, nums[MAXN];
void inOrderTrav(const int& root) {
	if(root == -1) return;
	inOrderTrav(nodes[root].lchild);
	nodes[root].data = nums[idx++];
	inOrderTrav(nodes[root].rchild);
}
int main() {
	queue<int> q; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d%d", &nodes[i].lchild, &nodes[i].rchild);
	for(int i = 0; i < n; i++) scanf("%d", &nums[i]);
	sort(nums, nums + n); inOrderTrav(0);
	for(q.push(0); !q.empty(); q.pop()) {
		const Node& node = nodes[q.front()];
		if(node.lchild != -1) q.push(node.lchild);
		if(node.rchild != -1) q.push(node.rchild);
		printf("%d%c", node.data, q.size() == 1 ? '\n':' ');
	}
	return 0;
}