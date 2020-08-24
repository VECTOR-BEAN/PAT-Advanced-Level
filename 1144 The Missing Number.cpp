#include<iostream>
constexpr int MAXN = 100001;
bool exist[MAXN];
int main() {
	int n, ans; scanf("%d", &n);
	for(int i = 0, val; i < n && scanf("%d", &val); ++i) {
		if(val > 0 && val < MAXN) exist[val] = true;
	}
	for(ans = 1; ans < MAXN && exist[ans]; ++ans);
	printf("%d\n", ans);
	return 0;
}