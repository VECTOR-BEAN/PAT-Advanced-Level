#include<iostream>
constexpr int MAXN = 10001;
int parent[MAXN], bird[MAXN];
int Find(const int& x) {
	int root;
	for(root = x; root != parent[root]; root = parent[root]);
	for(int c = x, p = parent[c]; p != root; c = p, p = parent[c]) parent[c] = root;
	return root;
}
void Union(const int& a, const int& b) {
	if(a == b) return;
	int roota = Find(a);
	int rootb = Find(b);
	if(roota != rootb) parent[rootb] = roota;
}
int main() {
	int n, q, birdNum = 0, treeNum = 0; scanf("%d", &n);
	for(int i = 0, k; i < n; i++) {
		scanf("%d", &k);
		for(int j = 0; j < k; j++) scanf("%d", &bird[j]);
		for(int j = 0; j < k; j++) {
			if(!parent[bird[j]]) parent[bird[j]] = bird[j];
		}
		for(int j = 0; j < k; j++) Union(bird[0], bird[j]);
	}
	for(int &i = birdNum, root; i+1 < MAXN && parent[i+1]; i++) {
		root = Find(i+1);
		if(!isRoot[root]) {
			treeNum++;
			isRoot[root] = true;
		}
	}
	scanf("%d", &q);
	printf("%d %d\n", treeNum, birdNum);
	for(int i = 0, b1, b2; i < q; i++) {
		scanf("%d%d", &b1, &b2);
		if(Find(b1) == Find(b2)) printf("Yes\n");
		else printf("No\n");
	}
 	return 0;
}