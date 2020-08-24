#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
constexpr int MAXN = 10000;
int minTransfer, vis[MAXN];
vector<int> graph[MAXN];
vector<int> ans, tempAns;  // minStops, minTransfers
unordered_map<int, unordered_map<int, int>> lines;
void DFS(const int& src, const int& dst) {
	if (vis[src]) return;
	vis[src] = true; tempAns.push_back(src);
	if (src == dst) {
		int transfers = -1, len = tempAns.size(), preLine = -1;
		for (int i = 1; i < len; i++) {
			if (lines[tempAns[i - 1]][tempAns[i]] != preLine) transfers++;
			preLine = lines[tempAns[i - 1]][tempAns[i]];
		}
		bool replace = ans.empty() || ans.size() > tempAns.size() || (ans.size() == tempAns.size() && transfers < minTransfer);
		if (replace) {
			ans = tempAns;
			minTransfer = transfers;
		}
	}
	else for (const int& dest : graph[src]) DFS(dest, dst);
	vis[src] = false; tempAns.pop_back();
}
int main() {
	int n, k; scanf("%d", &n);
	for (int line = 1, m, pre; line <= n; line++) {
		scanf("%d%d", &m, &pre);
		for (int i = 1, now; i < m; i++, pre = now) {
			scanf("%d", &now);
			graph[pre].push_back(now);
			graph[now].push_back(pre);
			lines[now][pre] = lines[pre][now] = line;
		}
	}
	scanf("%d", &k);
	for (int i = 0, src, dst, line; i < k; i++) {
		scanf("%d%d", &src, &dst);
		ans.clear(); tempAns.clear();
		minTransfer = 0x3fffffff;
		DFS(src, dst);
		src = ans.front(); line = lines[ans[0]][ans[1]];
		printf("%d\n", (int)ans.size() - 1);
		for (vector<int>::size_type j = 1; j < ans.size(); j++) {
			if (lines[ans[j - 1]][ans[j]] != line) {
				printf("Take Line#%d from %04d to %04d.\n", line, src, ans[j - 1]);
				src = ans[j - 1]; line = lines[ans[j - 1]][ans[j]];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", line, src, ans.back());
	}
	return 0;
}