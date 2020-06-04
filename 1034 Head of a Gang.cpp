#include<iostream>
#include<vector>
#include<map>
using namespace std;
constexpr int MAXN = 2000;

int pNum = 0, weight[MAXN] = {0}, vis[MAXN] = {0}, graph[MAXN][MAXN] = {0};
map<string, int> gangInfo, name2i;
map<int, string> i2name;

int change(string name) {
	auto it = name2i.find(name);
	if (it == name2i.end()) {
		name2i[name] = pNum;
		i2name[pNum] = name;
		return pNum++;
	}
	else return it->second;
}

void DFS(int v, int& gangHead, int& memNum, int& totalWeight) {
	vis[v] = 1;
	memNum++; 
	totalWeight += weight[v];
	if (weight[gangHead] < weight[v]) gangHead = v;
	for (int i = 0; i < pNum; i++) {
		if (vis[i] || !graph[v][i]) continue;
		else DFS(i, gangHead, memNum, totalWeight);
	}
}

int main() {
	int n, thrhd;
	scanf("%d %d", &n, &thrhd);
	for (int i = 0, time, s, d; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2 >> time;
		s = change(s1), d = change(s2);
		graph[d][s] = graph[s][d] = graph[s][d] + time;
		weight[s] += time, weight[d] += time;
	}
	for (int i = 0; i < pNum; i++) {
		int gangHead = i, memNum = 0, totalWeight = 0;
		DFS(i, gangHead, memNum, totalWeight);
		if (memNum > 2 && totalWeight/2 > thrhd) gangInfo[i2name[gangHead]] = memNum;
	}
	printf("%d\n", gangInfo.size());
	for (auto gang : gangInfo) printf("%s %d\n", gang.first.c_str(), gang.second);
	return 0;
}