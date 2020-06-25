#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
constexpr int MAXN = 200;
constexpr int INF = 0x3fffffff;
struct Node {
	int id, cost;
};
int nRoutes = 0, maxHp = 0;
int cost[MAXN], vis[MAXN], happiness[MAXN];
vector<int> path, tempPath, pre[MAXN];
vector<Node> Graph[MAXN];
map<int, string> i2s;
map<string, int> s2i;

void DFS(const int& src, const int& now) {
	tempPath.push_back(now);
	if (now == src) {
		nRoutes++; int tempHp = 0;
		for (auto id : tempPath) tempHp += happiness[id];
		if (tempHp > maxHp) {
			maxHp = tempHp;
			path = tempPath;
		}
		else if (tempHp == maxHp && tempPath.size() < path.size()) {
			path = tempPath;
		}
	}
	else for (const int& id : pre[now]) DFS(src, id);
	tempPath.pop_back();
}

void dijkstra(const int& src, const int& n) {
	fill(vis, vis + n, 0);
	fill(cost, cost + n, INF);
	cost[src] = 0; ;
	for (int i = 0; i < n; i++) {
		int u = -1, minCost = INF;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && cost[j] < minCost) {
				u = j;
				minCost = cost[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (const auto& city : Graph[u]) {
			if (vis[city.id]) continue;
			if (minCost + city.cost < cost[city.id]) {
				pre[city.id].clear(); pre[city.id].push_back(u);
				cost[city.id] = minCost + city.cost;
			}
			else if (minCost + city.cost == cost[city.id]) pre[city.id].push_back(u);
		}
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	string a, b, src; cin >> src;
	s2i[src] = 0; i2s[0] = src;
	for (int i = 1, hp; i < n; i++) {
		cin >> a >> hp;
		s2i[a] = i;
		i2s[i] = a;
		happiness[i] = hp;
	}
	for (int i = 0, cost; i < m; i++) {
		cin >> a >> b >> cost;
		Graph[s2i[a]].push_back({ s2i[b], cost });
		Graph[s2i[b]].push_back({ s2i[a], cost });
	}
	dijkstra(0, n);
	DFS(0, s2i["ROM"]);
	printf("%d %d %d %d\n", nRoutes, cost[s2i["ROM"]], maxHp, maxHp / (path.size() - 1));
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%s", i2s[path[i]].c_str());
		printf(i == 0 ? "\n" : "->");
	}
	return 0;
}