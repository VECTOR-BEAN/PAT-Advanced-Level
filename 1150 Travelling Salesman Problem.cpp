#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;
constexpr int MAXN = 201;
bool vis[MAXN];
int graph[MAXN][MAXN];
vector<int> path;
int main() {
	int n, m, q; scanf("%d%d", &n, &m);
	memset(graph[0], -1, sizeof(graph));
	for(int i = 0, u, v, d; i < m && scanf("%d%d%d", &u, &v, &d); ++i) {
		graph[u][v] = graph[v][u] = d;
	}
	scanf("%d", &q);
	int idx = -1, minDist = 0x3fffffff;
	for(int i = 1, k; i <= q && scanf("%d", &k); ++i) {
		int cnt = 0, dist = 0; bool flag = true;
		memset(vis, 0, sizeof(vis)); path.clear();
		for(int j = 0, val; j < k && scanf("%d", &val); ++j) path.push_back(val);
		for(int j = 1; j < (int) path.size(); ++j) {
			if(graph[path[j-1]][path[j]] != -1) {
				if(!vis[path[j]]) ++cnt;
				dist += graph[path[j-1]][path[j]];
				vis[path[j]] = true;
			}
			else flag = false;
		}
		if(!flag) printf("Path %d: NA (Not a TS cycle)\n", i);
		else if(cnt < n || path.front() != path.back()) printf("Path %d: %d (Not a TS cycle)\n", i, dist);
		else {
			if(k > n + 1) printf("Path %d: %d (TS cycle)\n", i, dist);
			else printf("Path %d: %d (TS simple cycle)\n", i, dist);
			if(dist < minDist) idx = i, minDist = dist;
		}
	}
	printf("Shortest Dist(%d) = %d\n", idx, minDist);
	return 0;
}