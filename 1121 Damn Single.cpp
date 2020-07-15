#include<iostream>
#include<memory.h>
constexpr int MAXN = 100000;
int couple[MAXN], lonely[MAXN];
int main() {
	int n, m, cnt;
	memset(couple, -1, sizeof(couple));
	scanf("%d", &n);
	for(int i = 0, c1, c2; i < n; i++) {
		scanf("%d%d", &c1, &c2);
		couple[c1] = c2;
		couple[c2] = c1;
	}
	scanf("%d", &m); cnt = m;
	for(int i = 0, id; i < m; i++) {
		scanf("%d", &id);
		if(couple[id] != -1 && lonely[couple[id]]) {
			cnt -= 2;
			lonely[couple[id]] = false;
		}
		else lonely[id] = true;
	}
	printf("%d\n", cnt);
	for(int i = 0; i < MAXN; i++) {
		if(lonely[i]) printf("%05d%c", i, --cnt?' ':'\n');
	}
	return 0;
}