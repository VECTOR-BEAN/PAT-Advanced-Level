#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;
constexpr int MAXV = 201;
vector<int> v;
bool vhash[MAXV], edge[MAXV][MAXV];
int main() {
	int nv, ne, m; scanf("%d%d", &nv, &ne);
	for (int i = 0, v1, v2; i < ne; ++i) {
		scanf("%d%d", &v1, &v2);
		edge[v1][v2] = edge[v2][v1] = true;
	}
	scanf("%d", &m);
	for (int query = 0, len; query < m && scanf("%d", &len); ++query) {
		v.clear(); bool flag = true, tag = true;
		for (int i = 0, v1; i < len && scanf("%d", &v1); ++i) {
			for(const int& v2 : v) flag = flag && edge[v1][v2];
			v.push_back(v1);
		}
		if (!flag) { printf("Not a Clique\n"); continue; } 
		memset(vhash, 0, sizeof(vhash)); // reset
		for(const int& v1 : v) vhash[v1] = true; // set hash value
		for (int v1 = 1; v1 <= nv && flag; ++v1) {
			if (vhash[v1]) continue;
			for(const int& v2 : v) tag = tag && edge[v1][v2];
			flag = !tag; tag = true;
		}
		if (!flag) printf("Not Maximal\n");
		else printf("Yes\n");
	}
	return 0;
}