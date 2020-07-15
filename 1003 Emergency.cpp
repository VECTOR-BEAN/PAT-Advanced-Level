#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 500;
const int INF = 0x3fffffff;
struct Node {
	int dest, length;
};
int team[MAXN], maxTeam[MAXN], pathNum[MAXN], vis[MAXN], dist[MAXN];
vector<Node> graph[MAXN];
void dijkstra(const int& src, const int& n) {
	fill(dist, dist + MAXN, INF);
	dist[src] = 0; pathNum[src] = 1; maxTeam[src] = team[src];
	for (int i = 0; i < n; i++) {
		int u = -1, minDist = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] || dist[j] > minDist) continue;
			u = j; minDist = dist[j];
		}
		if (u == -1) return;
		vis[u] = true;
		for (const Node& node : graph[u]) {
			if (vis[node.dest]) continue;
			if (minDist + node.length < dist[node.dest]) {
				dist[node.dest] = minDist + node.length;
				pathNum[node.dest] = pathNum[u];
				maxTeam[node.dest] = maxTeam[u] + team[node.dest];
			}
			else if (minDist + node.length == dist[node.dest]) {
				pathNum[node.dest] += pathNum[u];
				if (maxTeam[u] + team[node.dest] > maxTeam[node.dest]) 
					maxTeam[node.dest] = maxTeam[u] + team[node.dest];
			}
		}
	}
}
int main() {
	int n, m, src, dst; scanf("%d%d%d%d", &n, &m, &src, &dst);
	for (int i = 0; i < n; i++) scanf("%d", &team[i]);
	for (int i = 0, s, d, dis; i < m; i++) {
		scanf("%d%d%d", &s, &d, &dis);
		graph[s].push_back({ d, dis });
		graph[d].push_back({ s, dis });
	}
	dijkstra(src, n);
	printf("%d %d\n", pathNum[dst], maxTeam[dst]);
	return 0;
}