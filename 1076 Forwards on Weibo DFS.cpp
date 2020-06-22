// not recommended
#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;
constexpr int MAXN = 1001;
int layer[MAXN], counted[MAXN];
vector<int> Graph[MAXN];
void DFS(const int& src, const int& now, const int& tar, int& count) {
	if(now > tar) return;
	if(!counted[src]) count += 1; 
	layer[src] = now; counted[src] = 1;
	for(const int& childId : Graph[src]) {
		if (layer[childId] == -1) DFS(childId, now + 1, tar, count); // never visited
		else if (now + 1 < layer[childId]) DFS(childId, now + 1, tar, count); // visited again with lower level
	}
}
int main() {
	int n, l; scanf("%d%d", &n, &l);
	for(int i = 1, m; i <= n; i++) {
		scanf("%d", &m);
		for(int j = 0, master; j < m; j++) {
			scanf("%d", &master);
			Graph[master].push_back(i);
		}
	}
	scanf("%d", &n);
	for(int i = 0, ans, src; i < n; i++) {
		scanf("%d", &src); ans = -1;
		memset(layer, -1, sizeof(layer));
		memset(counted, 0, sizeof(counted));
		DFS(src, 0, l, ans);
		printf("%d\n", ans);
	}
}