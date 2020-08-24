#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
constexpr int MAXN = 10000;
int color[MAXN];
unordered_set<int> uniColor;
vector<pair<int, int>> edges;
int main() {
	int n, m, k; scanf("%d%d", &n, &m);
	for(int i = 0, u, v; i < m && scanf("%d%d", &u, &v); ++i) {
		edges.emplace_back(u, v);
	}
	scanf("%d", &k);
	for(int i = 0, flag; i < k; ++i) {
		uniColor.clear(); flag = true;
		for(int j = 0; j < n; ++j) scanf("%d", &color[j]);
		for(int j = 0; j < n; ++j) uniColor.insert(color[j]);
		for(const pair<int, int>& edge : edges) {
			flag = (color[edge.first] != color[edge.second]);
			if(!flag) break;
		}
		if(!flag) printf("No\n");
		else printf("%d-coloring\n", (int)uniColor.size());
	}
	return 0;
}
/*
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
4
0 1 0 1 4 1 0 1 3 0
0 1 0 1 4 1 0 1 0 0
8 1 0 1 4 1 0 5 3 0
1 2 3 4 5 6 7 8 8 9

4-coloring
No
6-coloring
No
*/