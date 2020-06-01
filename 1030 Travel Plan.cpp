#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
constexpr int MAXN = 500;
constexpr int INF = 0x3f3f3f3f;
struct Node {
	int dest, dist, cost;
	Node(int _dest, int _dist, int _cost): dest(_dest), dist(_dist), cost(_cost) {}
};

int vis[MAXN], path[MAXN], dist[MAXN], cost[MAXN];
vector<Node> graph[MAXN];
void dijkstra(int s, int d, int n){
	fill(vis, vis + MAXN, 0);
	fill(dist, dist + MAXN, INF);
	fill(cost, cost + MAXN, INF);
	path[s] = -1, dist[s] = cost[s] = 0;
	for(int i = 0; i < n; i++) {
		int u=-1, minDist = INF;
		for(int j = 0; j < n; j++) {
			if(vis[j]) continue;
			if(dist[j] < minDist) {
				u = j;
				minDist = dist[j];
			}
		}
		if(u == -1 || u == d) break;
		vis[u] = 1;
		for(auto node:graph[u]) {
			if(vis[node.dest]) continue;
			if(dist[u] + node.dist < dist[node.dest]) {
				path[node.dest] = u;
				dist[node.dest] = dist[u] + node.dist;
				cost[node.dest] = cost[u] + node.cost;
			}
			else if(dist[u] + node.dist == dist[node.dest] && cost[u] + node.cost < cost[node.dest]) {
				path[node.dest] = u;
				cost[node.dest] = cost[u] + node.cost;
			}
		}
	}
}

int main() {
	int n, m, s, d, temp;
	vector<int> ans;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for(int i = 0, src, dst, length, cost; i < m; i++) {
		scanf("%d%d%d%d", &src, &dst, &length, &cost);
		graph[src].push_back(Node(dst, length, cost));
		graph[dst].push_back(Node(src, length, cost));
	}
	dijkstra(s, d, n), temp = d;
	do {
		ans.push_back(temp);
		temp = path[temp];
	}
	while(temp != -1);
	for(int i = ans.size()-1; i >= 0; i--) printf("%d ", ans[i]);
	printf("%d %d\n", dist[d], cost[d]);
	return 0;
}