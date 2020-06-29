#include<iostream>
constexpr int MAXN = 100000;
constexpr int MAXK = 10001;
int hastTable[MAXK];
struct Node{
	int key, next;
} ans[2][MAXN+1], ori[MAXN];
int main() {
	int src, n; scanf("%d%d", &src, &n);
	for(int i = 0, addr, key, next; i < n; i++) {
		scanf("%d%d%d", &addr, &key, &next);
		ori[addr] = { key, next };
	}
	ans[0][MAXN].next = ans[1][MAXN].next = -1;
	for(int addr = src, kpSrc = MAXN, rmSrc = MAXN; addr != -1; addr = ori[addr].next) {
		const Node& node = ori[addr];
		int &flag = hastTable[abs(node.key)];
		int &last = flag ? rmSrc : kpSrc;
		ans[flag][last].next = addr;
		ans[flag][addr].key = node.key;
		ans[flag][addr].next = -1;
		last = addr; flag = 1;
	}
	for(int i = 0; i < 2; i++) {
		for(int p = ans[i][MAXN].next; p != -1; p = ans[i][p].next) {
			const Node& node = ans[i][p];
			if(node.next == -1) printf("%05d %d -1\n", p, node.key);
			else printf("%05d %d %05d\n", p, node.key, node.next);
		}
	}
	return 0;
}