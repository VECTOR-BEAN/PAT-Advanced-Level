#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
constexpr int MAXN = 100000;
double r, p, ans = 0;
struct Node {
	int data;
	vector<int> children;
} nodes[MAXN];

void DFS(int id, int layer) {
	if (nodes[id].children.empty()) ans += nodes[id].data * pow(1 + r, layer);
	else for (auto cid : nodes[id].children) DFS(cid, layer + 1);
}

int main() {
	int n; scanf("%d%lf%lf", &n, &p, &r); r /= 100;
	for (int i = 0; i < n; i++) {
		Node& node = nodes[i];
		scanf("%d", &node.data);
		for (int j = 0, id; j < node.data; j++) {
			scanf("%d", &id);
			node.children.push_back(id);
		}
		if (node.data == 0) scanf("%d", &node.data);
	}
	DFS(0, 0);
	printf("%.1f\n", ans * p);
	return 0;
}