#include<iostream>
#include<algorithm>
#include<cstring>
constexpr int MAXN = 100000;
using namespace std;
int pids[MAXN], age[MAXN], wealth[MAXN], query[MAXN][3];
char name[MAXN][9];

bool cmp(int a, int b) { 
	if(wealth[a] != wealth[b]) return wealth[a] > wealth[b];
	if(age[a] != age[b]) return age[a] < age[b];
	return strcmp(name[a], name[b]) < 0;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%s%d%d", name[i], &age[i], &wealth[i]);
		pids[i] = i;
	}
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &query[i][0], &query[i][1], &query[i][2]);
	}
	sort(pids, pids + n, cmp);
	for(int i = 0, count; i < m; i++) {
		printf("Case #%d:\n", i + 1); count = 0;
		for(int j = 0, pid = pids[j]; j < n && count < query[i][0]; pid = pids[++j]) {
			if(age[pid] >= query[i][1] && age[pid] <= query[i][2]) {
				printf("%s %d %d\n", name[pid], age[pid], wealth[pid]);
				count++;
			}
		}
		if(count == 0) printf("None\n");
	}
	return 0;
}