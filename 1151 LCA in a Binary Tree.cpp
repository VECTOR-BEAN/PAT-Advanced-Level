#include<iostream>
#include<unordered_map>
using namespace std;
constexpr int MAXN = 10000;
int pre[MAXN], in[MAXN];
unordered_map<int, int> mp;
int main() {
	int m, n; scanf("%d%d", &m, &n);
	for(int i = 0; i < n && scanf("%d", &in[i]); ++i) mp[in[i]] = i;
	for(int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	for(int i = 0, u, v; i < m && scanf("%d%d", &u, &v); ++i) {
		if(!mp.count(u) && !mp.count(v)) 
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if(!mp.count(u) || !mp.count(v))
			printf("ERROR: %d is not found.\n", mp.count(u) ? v : u);
		else {
			int rtidx = mp[pre[0]], uidx = mp[u], vidx = mp[v];
			// condition below can be substituted with: uidx != rtidx && vidx != rtidx && ((uidx < rtidx) == (vidx < rtidx))
			for(int rtidxPre = 0, lo = 0; true; rtidx = mp[pre[rtidxPre]]) {
				if(uidx < rtidx && vidx < rtidx) rtidxPre += 1;
				else if(uidx > rtidx && vidx > rtidx){ 
					rtidxPre += 1 + (rtidx - lo);
					lo = rtidx + 1;
				}
				else break;
			}
			if(u == in[rtidx] || v == in[rtidx])
				printf("%d is an ancestor of %d.\n", in[rtidx], u == in[rtidx] ? v : u);
			else
				printf("LCA of %d and %d is %d.\n", u, v, in[rtidx]);
		}
	} 
	return 0;
}