#include<iostream>
#include<algorithm>
using namespace std;
constexpr int MAXN = 100000;
int dist[MAXN];
int main() {
	int n, ans; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &dist[i]);
	sort(dist, dist + n, greater<int>());
	for(ans = 0; ans < n && dist[ans] > ans + 1; ans++);
	printf("%d\n", ans);
	return 0;
}