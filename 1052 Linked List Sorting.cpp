#include<iostream>
#include<algorithm>
using namespace std;
constexpr int MAXN = 100000;
struct Node{
	int addr, key, next, valid;
}temp, nodes[MAXN];
bool cmp(Node a, Node b) {
	if(a.valid != b.valid) return a.valid > b.valid;
	return a.key < b.key; 
}
int main() {
	int n, addr, count = 0;
	scanf("%d%d", &n, &addr);
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d", &temp.addr, &temp.key, &temp.next);
		nodes[temp.addr] = temp;
	}
	if(addr == -1) {
		printf("0 -1\n");
		return 0;
	}
	for(int p = addr; p != -1; p = nodes[p].next) {
		nodes[p].valid = 1;
		count++;
	}
	sort(nodes, nodes+MAXN, cmp);
	printf("%d %05d\n", count, nodes[0].addr);
	for(int i = 0; i < count; i++) {
		if(i < count - 1) printf("%05d %d %05d\n", nodes[i].addr, nodes[i].key, nodes[i+1].addr);
		else printf("%05d %d -1\n", nodes[i].addr, nodes[i].key);
	}
	return 0;
}