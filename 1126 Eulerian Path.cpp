#include<iostream>
#include<vector>
using namespace std;
constexpr int MAXN = 501;
bool vis[MAXN];
vector<int> graph[MAXN];
void DFS(const int& root, int& count) {
	if(vis[root]) return;
	vis[root] = true; count++;
	for(const int& child : graph[root]) DFS(child, count);
}
int main() {
	int n, m, count = 0, oddCount = 0; scanf("%d%d", &n, &m);
	for(int i = 0, s, d; i < m; i++) {
		scanf("%d%d", &s, &d);
		graph[s].push_back(d);
		graph[d].push_back(s);
	}
	DFS(1, count);
	for(int i = 1; i <= n; i++) {
		if(graph[i].size() % 2 == 1) oddCount++;
		printf("%llu%c", graph[i].size(), i == n ? '\n' : ' ');
	}
	if(oddCount == 0 && count == n) printf("Eulerian\n");
	else if(oddCount == 2 && count == n) printf("Semi-Eulerian\n");
	else printf("Non-Eulerian\n");
	return 0;
}