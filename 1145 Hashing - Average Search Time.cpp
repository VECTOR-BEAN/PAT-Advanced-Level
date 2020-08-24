#include<iostream>
#include<cmath>
constexpr int MAXN = 10007;
int table[MAXN];
bool prime(const int& val) {
	if(val < 2) return false;
	for(int i = 2, n = sqrt(val); i <= n; ++i) {
		if(val % i == 0) return false;
	}
	return true;
}
int find(const int& val, const int& tSize) {
	for(int ans = 0, pos; ans < tSize; ++ans) {
		pos = (val + ans * ans) % tSize;
		if(val == table[pos] || !table[pos]) return ans + 1;
	}
	return tSize + 1;
}
int main() {
	int tSize, n, m, ans = 0; scanf("%d%d%d", &tSize, &n, &m);
	while(!prime(tSize)) ++tSize;
	for(int i = 0, val; i < n && scanf("%d", &val); ++i) {
		bool flag = true;
		for(int offset = 0, pos; offset < tSize && flag; ++offset) {
			pos = (val + offset * offset) % tSize;
			if(!table[pos]) table[pos] = val, flag = false;
		}
		if(flag) printf("%d cannot be inserted.\n", val);
	}
	for(int i = 0, val; i < m && scanf("%d", &val); ++i) {
		ans += find(val, tSize);
	}
	printf("%.1f\n", (double)ans / m);
	return 0;
}