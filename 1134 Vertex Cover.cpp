#include<iostream>
#include<memory.h>
constexpr int MAXN = 10000;
struct Edge{
	int e1, e2;
} egdes[MAXN];
bool vertex[MAXN];
int main() {
	int n, m, k; scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) scanf("%d%d", &egdes[i].e1, &egdes[i].e2);
	scanf("%d", &k);
	for(int i = 0, nv, flag; i < k && scanf("%d", &nv); i++) {
		memset(vertex, 0, sizeof(vertex)); flag = true;
		for(int j = 0, v; j < nv && scanf("%d", &v); j++) vertex[v] = true;
		for(int j = 0; j < m && flag; j++) flag = vertex[egdes[j].e1] || vertex[egdes[j].e2];
		printf("%s\n", flag ? "Yes":"No");
	}
	return 0;
}