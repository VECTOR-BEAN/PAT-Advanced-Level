#include<iostream>
#include<memory.h>
#include<algorithm>
#include<cstdlib>
#include<unordered_map>
using namespace std;
constexpr int MAXN = 1011;
constexpr int INF = 0x3fffffff;
unordered_map<int, unordered_map<int, int>> Graph;
int dist[MAXN], vis[MAXN];
bool dijkstra(int src, int n, int m, int r) {
	fill(dist + 1, dist + n + m + 1, INF);
	memset(vis, 0, sizeof(vis));
	dist[src] = 0;
	for (int i = 0; i < n + m; i++) {
		int u = -1, minDist = INF;
		for (int j = 1; j <= n + m; j++) {
			if (!vis[j] && dist[j] < minDist) {
				u = j;
				minDist = dist[j];
			}
		}
		if (u == -1 || (dist[u] > r && u <= n)) return false;
		vis[u] = 1;
		for(const auto& kv : Graph[u]) {
			if(!vis[kv.first] && dist[u] + kv.second < dist[kv.first]) 
				dist[kv.first] = dist[u] + kv.second;
		}
	}
	return true;
}
int main() {
	int n, m, k, r; scanf("%d%d%d%d", &n, &m, &k, &r);
	auto getIndex = [n](const char arr[]) {return arr[0] == 'G' ? n + atoi(arr + 1) : atoi(arr); };
	for (int i = 0, src, dest, length; i < k; i++) {
		char s[5], d[5];
		scanf("%s%s%d", s, d, &length);
		src = getIndex(s); dest = getIndex(d);
		Graph[src][dest] = Graph[dest][src] = length;
	}
	int ansId = -1; double minDist = 0, totalDist = INF;
	for (int index = n + 1; index <= n + m; index++) {
		if(!dijkstra(index, n, m, r)) continue;
		double tMinDist = INF, tTotalDist = 0;
		for (int i = 1; i <= n; i++) {
			tTotalDist += dist[i];
			if (dist[i] < tMinDist) tMinDist = dist[i];
		}
		if (tMinDist > minDist) {
			ansId = index;
			minDist = tMinDist;
			totalDist = tTotalDist;
		}
		else if (tMinDist == minDist && tTotalDist < totalDist) {
			ansId = index;
			totalDist = tTotalDist;
		}
	}
	if (ansId == -1) printf("No Solution\n");
	else printf("G%d\n%.1f %.1f\n", ansId - n, minDist, totalDist / n);
	return 0;
}