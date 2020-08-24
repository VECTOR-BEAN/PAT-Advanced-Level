#include <iostream>
#include <unordered_map>
using namespace std;
constexpr int MAXN = 50000;
int pre[MAXN], in[MAXN];
unordered_map<int, int> mp;
int main() {
	int n, pos = 0; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	for (int i = 0; i < n; i++) mp[in[i]] = i;
	for (int lo = 0, hi = n - 1; lo < hi; pos++) {
		if (mp[pre[pos]] > lo) hi = mp[pre[pos]] - 1;
		else lo = mp[pre[pos]] + 1;
	}
	printf("%d\n", pre[pos]);
	return 0;
}