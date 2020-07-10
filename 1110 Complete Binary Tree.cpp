#include<iostream>
#include<queue>
using namespace std;
constexpr int MAXN = 20;
struct Node{
	int lchild, rchild;
}tree[MAXN];
bool notRoot[MAXN];
bool isCBT(const int& n, int& root, int& lastNode) {
	bool flag = true; queue<int> q;
	for(root = 0; root < n && notRoot[root]; root++);
	for(q.push(root); !q.empty(); q.pop()) {
		const Node& node = tree[q.front()];
		if(node.lchild != -1) q.push(node.lchild);
		if(node.rchild != -1) q.push(node.rchild);
		if(q.size() == 1) lastNode = q.front();
		if(flag) {
			if(node.lchild == -1 && node.rchild == -1) flag = false;
			else if(node.lchild != -1 && node.rchild == -1) flag = false;
			else if(node.lchild == -1 && node.rchild != -1) return false;
			else continue;
		}
		else {
			if(node.lchild == -1 && node.rchild == -1) continue;
			return false;
		}
	}
	return true;
}

int main() {
	int n, root, ans; char a[3], b[3]; 
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s %s", a, b);
		if(isdigit(a[0])) {
			tree[i].lchild = atoi(a);
			notRoot[tree[i].lchild] = true;
		}
		else tree[i].lchild = -1;
		if(isdigit(b[0])) {
			tree[i].rchild = atoi(b);
			notRoot[tree[i].rchild] = true;
		}
		else tree[i].rchild = -1;
	}
	if(isCBT(n, root, ans)) printf("YES %d\n", ans);
	else printf("NO %d\n", root);
	return 0;
}