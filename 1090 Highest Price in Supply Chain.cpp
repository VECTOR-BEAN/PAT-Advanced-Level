#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
constexpr int MAXN = 100000;
int maxDepth = 0, num = 0;
vector<int> children[MAXN];
void DFS(const int& src, const int& depth) {
	if(children[src].empty()) {
		if(depth > maxDepth) {
			maxDepth = depth;
			num = 1;
		}
		else if(depth == maxDepth) num++;
	}
	else {
		for(const int& child : children[src]) 
			DFS(child, depth + 1);	
	}
}

int main() {
	int n, src; double price, rate; 
	scanf("%d %lf %lf", &n, &price, &rate);
	for(int i = 0, p; i < n; i++) {
		scanf("%d", &p);
		if(p != -1) children[p].push_back(i);
		else src = i;
	}
	DFS(src, 0);
	printf("%.2f %d", price * pow(1 + rate / 100, maxDepth), num);
	return 0;
}
/*
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
1.854542 2

9 1.80 2.00
1 5 4 4 -1 4 5 3 6
1.910174 2
*/