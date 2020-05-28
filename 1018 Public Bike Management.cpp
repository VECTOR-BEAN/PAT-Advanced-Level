#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
constexpr int MAXN = 501;
constexpr int INF = 0x3f3f3f3f;
struct Node {
	int dest, dist;
	Node() {}
	Node(int _dest, int _dist) : dest(_dest), dist(_dist) {}
};

int c, n, dest, m;
int minNeed = INF, minRemain = INF;
int bike[MAXN], dist[MAXN], vis[MAXN];
vector<int> pre[MAXN];
vector<Node> Graph[MAXN];
vector<int> path, tempPath;

void DFS(int s) {
	tempPath.push_back(s);
	if (s == 0) {
		int remain = 0, need = 0;
		for (int i = tempPath.size() - 2; i >= 0; i--) {
			remain += bike[tempPath[i]] - c / 2;
			if (remain < 0) {
				need += abs(remain);
				remain = 0;
			}
		}
		if (need < minNeed) {
			path = tempPath;
			minNeed = need;
			minRemain = remain;
		}
		else if (need == minNeed && remain < minRemain) {
			path = tempPath;
			minRemain = remain;
		}
	}
	else {
		for (auto u : pre[s]) DFS(u);
	}
	tempPath.pop_back();
}

void dijkstra() {
	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
		vis[i] = 0;
	}
	dist[0] = 0;

	for (int i = 0; i <= n; i++) {
		int u = -1, minDist = INF;
		for (int j = 0; j <= n; j++) {
			if (!vis[j] && dist[j] < minDist) {
				minDist = dist[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = 1;
		for (auto road : Graph[u]) {
			if (!vis[road.dest]) {
				if (dist[u] + road.dist < dist[road.dest]) {
					dist[road.dest] = dist[u] + road.dist;
					pre[road.dest].clear();
					pre[road.dest].push_back(u);
				}
				else if (dist[u] + road.dist == dist[road.dest]) {
					pre[road.dest].push_back(u);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d", &c, &n, &dest, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &bike[i]);
	for (int i = 0, s, d, l; i < m; i++) {
		scanf("%d%d%d", &s, &d, &l);
		Graph[s].push_back(Node(d, l));
		Graph[d].push_back(Node(s, l));
	}
	dijkstra();
	DFS(dest);
	printf("%d ", minNeed);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if (i != 0) printf("->");
		else printf(" ");
	}
	printf("%d\n", minRemain);
	return 0;
}