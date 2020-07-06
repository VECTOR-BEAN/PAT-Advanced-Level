#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
constexpr int MAXN = 1001;
vector<int> hobbies[MAXN];
int parent[MAXN], hobby[MAXN], cluster[MAXN], ans[MAXN];
int Find(const int& x) {
	int root; vector<int> nonRoots;
	for(root = x; root != parent[root]; root = parent[root]) nonRoots.push_back(root);
	for(const int& node : nonRoots) parent[node] = root;
	return root;
}
void Union(const int& a, const int& b) {
	int parentA = Find(a);
	int parentB = Find(b);
	if(parentA != parentB) parent[parentB] = parentA;
}
int main() {
	int n, cnt = 0; scanf("%d", &n);
	for(int i = 1; i <= n; i++) parent[i] = i;
	for(int i = 1, k; i <= n; i++) {
		scanf("%d:", &k);
		for(int j = 0, hb; j < k; j++) {
			scanf("%d", &hb);
			hobbies[i].push_back(hb);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(const int& hobbyId : hobbies[i]) {
			if(!hobby[hobbyId]) hobby[hobbyId] = i;
			Union(i, Find(hobby[hobbyId]));
		}
	}
	for(int i = 1; i <= n; i++) cluster[Find(i)]++;
	for(int i = 1; i <= n; i++) if(cluster[i]) ans[cnt++] = cluster[i];
	sort(ans, ans + cnt, [](const int& a, const int& b) {return a > b;});
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++) printf("%d%c", ans[i], i == cnt - 1 ? '\n': ' ');
	return 0;
}