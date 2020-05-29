#include<iostream>
#include<set>
#include<vector>
#include<memory.h>
using namespace std;
constexpr int MAXN = 10001;
int maxHeight=0, vis[MAXN];
set<int> ans;
vector<int> temp, Graph[MAXN];

void DFS(int root, int height) {
	vis[root] = true;
	if(height > maxHeight) {
		temp.clear();
		temp.push_back(root);
		maxHeight = height;
	}
	else if(height == maxHeight) {
		temp.push_back(root);
	}
	for(auto v: Graph[root]) {
		if(!vis[v]) DFS(v, height + 1);
	}
}

int main(){
	int n, cnt = 0;
	scanf("%d", &n);
	for(int i = 1, v1, v2; i < n; i++) {
		scanf("%d%d", &v1, &v2);
		Graph[v1].push_back(v2);
		Graph[v2].push_back(v1);
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			cnt++;
			DFS(i, 1);
		}
	}
	if(cnt > 1) {
		printf("Error: %d components\n", cnt);
	}
	else{
		for(auto i: temp) ans.insert(i);
		memset(vis, 0, sizeof(vis));
		DFS(temp.front(), 1);
		for(auto i: temp) ans.insert(i);
		for(auto i: ans) printf("%d\n", i);
	}
	return 0;
}