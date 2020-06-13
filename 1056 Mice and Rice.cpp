#include<iostream>
#include<queue>
constexpr int MAXN = 1000;
using namespace std;
int weight[MAXN], ranking[MAXN];
queue<int> q;
int main() {
	int np, ng;
	scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; i++) scanf("%d", &weight[i]);
	for(int i = 0, order; i < np; i++) {
		scanf("%d", &order); 
		q.push(order);
	}
	for(int n = q.size(), group; !q.empty(); n = q.size()) {
		if(n == 1) { ranking[q.front()] = 1; break; }
		group = n % ng == 0 ? n / ng : n / ng + 1;
		for(int i = 0, maxId = q.front(); i < n; i += ng) {
			for(int count = 0; count < ng && i + count < n; count++, q.pop()) {
				ranking[q.front()] = group + 1;
				if(weight[q.front()] > weight[maxId]) maxId = q.front();
			}
			q.push(maxId); maxId = q.front();
		}
	}
	for(int i = 0; i < np; i++) printf("%d%c", ranking[i], i == np - 1 ? '\n' : ' ');
	return 0;
}