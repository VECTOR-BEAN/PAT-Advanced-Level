#include<iostream>
#include<vector>
#include<queue>
using namespace std;
constexpr int MAXN = 100;
vector<int> children[MAXN];
void BFS(const int& root, int& maxGen, int& maxNum){
	int tempGen = 0, tempNum = 1; 
	queue<int> q; q.push(root);
	while(!q.empty()) {
		tempGen++; tempNum = q.size();
		if(tempNum > maxNum) {
			maxNum = tempNum;
			maxGen = tempGen;
		}
		for(int i = 0, p; i < tempNum; i++) {
			p = q.front(); q.pop();
			for(const int& child : children[p]) q.push(child);
		}
	}
}
int main() {
	int n, m, maxGen = 1, maxNum = 1; scanf("%d%d", &n, &m);
	for(int i = 0, id, k; i < m; i++) {
		scanf("%d%d", &id, &k);
		for(int j = 0, cid; j < k; j++) {
			scanf("%d", &cid);
			children[id].push_back(cid);
		}
	}
	BFS(1, maxGen, maxNum);
	printf("%d %d\n", maxNum, maxGen);
	return 0;
}