#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
constexpr int MAXN = 100;
vector<int> weight, path, tree[MAXN];

bool cmp(int a, int b) { return weight[a] > weight[b]; }

void DFS(int root, int req) {
	if(req < 0) return;
	path.push_back(root);
	if (tree[root].empty()) {
		if(req == 0) {
			for(int i = 0, len = path.size(); i < len; i++) {
				printf("%d%c", weight[path[i]], i == len-1?'\n':' ');
			}
		}
	}
	else {
		for(auto sonId : tree[root]) {
			DFS(sonId, req - weight[sonId]);
		}
	}
	path.pop_back();
}

int main() {
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s); weight.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &weight[i]);
	for (int i = 0, id, num; i < m; i++) {
		scanf("%d%d", &id, &num);
		for (int j = 0, sonId; j < num; j++) {
			scanf("%d", &sonId);
			tree[id].push_back(sonId);
		}
		sort(tree[id].begin(), tree[id].end(), cmp);
	}
	DFS(0, s- weight[0]);
	return 0;
}