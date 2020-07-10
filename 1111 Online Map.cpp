#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
constexpr int MAXN = 500;
constexpr int INF = 0x7fffffff;
struct Node{
	int dest, dist, cost;
};
int cost[MAXN], costPath[MAXN], dist[MAXN], distPath[MAXN], nNum[MAXN], vis[MAXN];
vector<int> ansDist, ansTime;
vector<Node> graph[MAXN];
void dijkstraDist(const int& src, const int& n) {
	// fill(vis, vis + n, 0); // 0 is default value
	fill(dist, dist + n, INF);
	fill(cost, cost + n, INF);
	dist[src] = cost[src] = 0; distPath[src] = -1;
	for(int i = 0, u, minDist; i < n; i++) {
		u = -1; minDist = INF;
		for(int j = 0; j < n; j++) {
			if(vis[j] || dist[j] >= minDist) continue;
			u = j; minDist = dist[j];
		}
		if(u == -1) return; vis[u] = true;
		for(const Node& node : graph[u]) {
			if(vis[node.dest] || minDist + node.dist > dist[node.dest]) continue;
			if(minDist + node.dist < dist[node.dest]) {
				dist[node.dest] = minDist + node.dist;
				cost[node.dest] = cost[u] + node.cost;
				distPath[node.dest] = u;
			}
			else if(minDist + node.dist == dist[node.dest]){
				if(cost[u] + node.cost >= cost[node.dest]) continue;
				cost[node.dest] = cost[u] + node.cost;
				distPath[node.dest] = u;
			}
		}
	}
}
void dijkstraTime(const int& src, const int& n) {
	fill(vis, vis + n, 0);
	// fill(nNum, nNum + n, 0); // 0 is default value
	fill(cost, cost + n, INF);
	cost[src] = nNum[src] = 0; costPath[src] = -1;
	for(int i = 0, u, minCost; i < n; i++) {
		u = -1; minCost = INF;
		for(int j = 0; j < n; j++) {
			if(vis[j] || cost[j] >= minCost) continue;
			u = j; minCost = cost[j];
		}
		if(u == -1) return; vis[u] = true;
		for(const Node& node : graph[u]) {
			if(vis[node.dest] || minCost + node.cost > cost[node.dest]) continue;
			if(minCost + node.cost < cost[node.dest]) {
				cost[node.dest] = minCost + node.cost;
				nNum[node.dest] = nNum[u] + 1;
				costPath[node.dest] = u;
			}
			else if(minCost + node.cost == cost[node.dest]) {
				if(nNum[u] + 1 >= nNum[node.dest]) continue;
				nNum[node.dest] = nNum[u] + 1;
				costPath[node.dest] = u;
			}
		}
	}
}
int main() {
	int n, m, src, dest; scanf("%d%d", &n, &m);
	for(int i = 0, v1, v2, oneWay, l, t; i < m; i++) {
		scanf("%d%d%d%d%d", &v1, &v2, &oneWay, &l, &t);
		graph[v1].push_back({v2, l, t});
		if(!oneWay) graph[v2].push_back({v1, l, t});
	}
	scanf("%d%d", &src, &dest);
	dijkstraDist(src, n);
	dijkstraTime(src, n);
	for(int p = dest; p != -1; p = distPath[p]) ansDist.push_back(p);
	for(int p = dest; p != -1; p = costPath[p]) ansTime.push_back(p);
	if(ansDist == ansTime) {
		printf("Distance = %d; Time = %d: ", dist[dest], cost[dest]);
		for(auto it = ansDist.rbegin(); it != ansDist.rend(); ++it) {
			printf("%d%s", *it, *it == ansDist.front() ? "\n" : " -> ");
		}
	}
	else {
		printf("Distance = %d: ", dist[dest]);
		for(auto it = ansDist.rbegin(); it != ansDist.rend(); ++it) {
			printf("%d%s", *it, *it == ansDist.front() ? "\n" : " -> ");
		}
		printf("Time = %d: ", cost[dest]);
		for(auto it = ansTime.rbegin(); it != ansTime.rend(); ++it) {
			printf("%d%s", *it, *it == ansTime.front() ? "\n" : " -> ");
		}
	}
	return 0;
}