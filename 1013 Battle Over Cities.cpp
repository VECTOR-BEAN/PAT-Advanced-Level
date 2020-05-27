#include<cstdio>
#include<vector>
using namespace std;
constexpr int MAXN = 1000;
vector<int> Graph[MAXN];
bool vis[MAXN];

void DFS(int n, int vertex, int del) {
	if(vertex == del) return;
	vis[vertex] = true;
	for(auto v: Graph[vertex]) if (!vis[v]) DFS(n, v, del);
}

int main(){
	int N, M, K;
	vector<int> query;
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 0, s, d; i < M; i++) {
		scanf("%d%d", &s, &d);
		Graph[s].push_back(d);
		Graph[d].push_back(s);
	}
	for(int i = 0, q; i < K; i++) {
		scanf("%d", &q);
		query.push_back(q);
	}

	for(auto del: query) {
		int num = 0;
		for(int i = 1; i <= N; i++) vis[i] = false; 
		for(int city = 1; city <= N; city++) {
			if(!vis[city] && city != del) {
				num++;
				DFS(N, city, del);
			}
		}
		printf("%d\n", num - 1);
	}
	return 0;
}

/*
3 2 3
1 2
1 3
1 2 3
*/