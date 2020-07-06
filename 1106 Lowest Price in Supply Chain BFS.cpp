#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
constexpr int MAXN = 100000;
int layer[MAXN];
vector<int> tree[MAXN];
void BFS(const int& root) {
	queue<int> q;
	for(q.push(root); !q.empty(); q.pop()) {
		for(const int& sonId : tree[q.front()]) {
			layer[sonId] = layer[q.front()] + 1;
			q.push(sonId);
		}
	}
}
int main() {
	int n; double price, rate;
	scanf("%d%lf%lf", &n, &price, &rate);
	for(int i = 0, k; i < n; i++) {
		scanf("%d", &k);
		for(int j = 0, temp; j < k; j++) {
			scanf("%d", &temp);
			tree[i].push_back(temp);
		}
	}
	BFS(0);
	int minLayer = 0x3fffffff, count = 0;
	for(int i = 0; i < n; i++) {
		if(tree[i].empty()) {
			if(layer[i] < minLayer) {
				minLayer = layer[i];
				count = 1;
			}
			else if(layer[i] == minLayer) count++;
		}
	}
	printf("%.4f %d\n", price * pow(1 + rate/100, minLayer), count);
	return 0;
}