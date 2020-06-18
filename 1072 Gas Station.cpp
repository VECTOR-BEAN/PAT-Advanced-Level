#include<iostream>
#include<memory.h>
#include<algorithm>
#include<cstdlib>
using namespace std;
constexpr int MAXN = 1011;
constexpr int INF = 0x3fffffff;
int Graph[MAXN][MAXN], dist[MAXN], vis[MAXN];
void dijkstra(int src, int n, int m) {
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
		if (u == -1) return;
		vis[u] = 1;
		for (int j = 1; j <= n + m; j++) {
			if (!vis[j] && dist[u] + Graph[u][j] < dist[j]) {
				dist[j] = dist[u] + Graph[u][j];
			}
		}
	}
}
int main() {
	fill(Graph[0], Graph[0] + MAXN * MAXN, INF);
	for (int i = 0; i < MAXN; i++) Graph[i][i] = 0;
	int n, m, k, r; scanf("%d%d%d%d", &n, &m, &k, &r);
	auto getIndex = [n](char arr[]) {return arr[0] == 'G' ? n + atoi(arr + 1) : atoi(arr); };
	for (int i = 0, src, dest, length; i < k; i++) {
		char s[5], d[5];
		scanf("%s%s%d", s, d, &length);
		src = getIndex(s); dest = getIndex(d);
		if (length < Graph[src][dest]) Graph[src][dest] = Graph[dest][src] = length;
	}
	int ansId = -1; double minDist = 0, totalDist = INF;
	for (int index = n + 1; index <= n + m; index++) {
		dijkstra(index, n, m);
		double tMinDist = INF, tMaxDist = 0, tTotalDist = 0;
		for (int i = 1; i <= n; i++) {
			tTotalDist += dist[i];
			if (dist[i] < tMinDist) tMinDist = dist[i];
			if (dist[i] > tMaxDist) tMaxDist = dist[i];
		}
		if (tMaxDist > r) continue;
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