#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
	int next, flag;
	Node() {}
	Node(int _n, int _f): next(_n), flag(_f){}
};

unordered_map<int, Node> mp;

int main() {
	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);
	for(int i = 0, s, d; i < n; i++) {
		scanf("%d %*c %d", &s, &d);
		mp[s] = Node(d, 0);
	}
	;
	while(s1 != -1) {
		mp[s1].flag = 1;
		s1 = mp[s1].next;
	}
	while(s2 != -1 && !mp[s2].flag) s2 = mp[s2].next;
	if(s2 == -1) printf("-1\n");
	else printf("%05d\n", s2);
	return 0;
}