#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;
const int MAXN = 1001;
const int MAXK = 100;
int oriCnt[MAXN], cnt[MAXN], ans[MAXK];
vector<int> graph[MAXN];
int main() {
	int n, m, k, len = 0; scanf("%d%d", &n, &m);
	for (int i = 0, v1, v2; i < m && scanf("%d%d", &v1, &v2); ++i) {
		graph[v1].push_back(v2);
		++oriCnt[v2];
	}
	scanf("%d", &k);
	for (int i = 0, topo; i < k; ++i) {
		memset(cnt, 0, sizeof(cnt)); topo = true;
		for (int j = 1; j <= n; ++j) cnt[j] = oriCnt[j];
		for (int j = 0, v; j < n && scanf("%d", &v); ++j) {
			if(cnt[v]) topo = false;
			for (const int& node : graph[v]) --cnt[node];
		}
		if(!topo) ans[len++] = i;
	}
	for(int i = 0; i < len; ++i) printf("%d%c", ans[i], i == len-1?'\n':' ');
	return 0;
}