#include<iostream>
#include<vector>
using namespace std;
constexpr int MAXN = 100000;
struct Node{
	int addr, data, next;
} nodes[MAXN];
vector<Node> ans;
int main() {
	int src, n, thrhd; scanf("%d%d%d", &src, &n, &thrhd);
	auto classify = [&thrhd](const Node& node) {return node.data < 0 ? 1 : (node.data <= thrhd ? 2 : 3); };
	for(int i = 0, addr, data, next; i < n; i++) {
		scanf("%d%d%d", &addr, &data, &next);
		nodes[addr] = {addr, data, next};
	}
	for(int ptr = src; ptr != -1; ptr = nodes[ptr].next) 
		if(classify(nodes[ptr]) == 1) ans.push_back(nodes[ptr]);
	for(int ptr = src; ptr != -1; ptr = nodes[ptr].next)
		if(classify(nodes[ptr]) == 2) ans.push_back(nodes[ptr]);
	for(int ptr = src; ptr != -1; ptr = nodes[ptr].next) 
		if(classify(nodes[ptr]) == 3) ans.push_back(nodes[ptr]);
	for(vector<int>::size_type i = 0; i < ans.size() - 1; i++) {
		printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i+1].addr);
	}
	printf("%05d %d -1\n", ans.back().addr, ans.back().data);
	return 0;
}