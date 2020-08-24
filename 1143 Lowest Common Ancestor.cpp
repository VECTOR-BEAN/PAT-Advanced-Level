#include<iostream>
#include<unordered_set>
using namespace std;
constexpr int MAXN = 10000;
unordered_set<int> st;
int pre[MAXN];
int main() {
	int m, n; scanf("%d%d", &m, &n);
	auto between = [](int lo, int hi, const int& val) {
		if(hi < lo) swap(lo, hi);
		return lo <= val && val <= hi;
	}; 
	for(int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	for(int i = 0; i < n; ++i) st.insert(pre[i]);
	for(int i = 0, u, v, j; i < m && scanf("%d%d", &u, &v); ++i) {
		if(!st.count(u) && !st.count(v))
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if(!st.count(u) || !st.count(v))
			printf("ERROR: %d is not found.\n", !st.count(u) ? u : v);
		else {
			for(j = 0; j < n; j++) if(between(u, v, pre[j])) break;
			if (pre[j] == u || pre[j] == v)
				printf("%d is an ancestor of %d.\n", pre[j], pre[j] == u ? v : u);
			else
				printf("LCA of %d and %d is %d.\n", u, v, pre[j]);
		}
	}
	return 0;
}
/*
6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99 
*/