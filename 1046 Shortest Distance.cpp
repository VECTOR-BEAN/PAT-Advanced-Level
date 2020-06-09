#include<iostream>
#include<algorithm>
using namespace std;
constexpr int MAXN = 100001;
constexpr int MAXM = 10000;
int distSuffix[MAXN], ans[MAXM];

int main() {
	int n, m; distSuffix[0] = 0;
	scanf("%d", &n);
	for(int i = 1, temp; i <= n; i++) {
		scanf("%d", &temp);
		distSuffix[i] = distSuffix[i-1] + temp;
	}
	scanf("%d", &m);
	for(int i = 0, s, d, dist; i < m; i++) {
		scanf("%d %d", &s, &d);
		if(d < s) swap(s, d);
		dist = distSuffix[d-1] - distSuffix[s - 1];
		ans[i] = (dist < distSuffix[n] - dist) ? dist : distSuffix[n] - dist;
	}
	for(int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}