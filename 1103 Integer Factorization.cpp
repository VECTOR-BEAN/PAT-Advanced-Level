#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
constexpr int MAXN = 21;
int n, k, p, maxFacSum = 0, table[MAXN];
vector<int> tempAns, ans;
void DFS(const int& index, const int& curSum) {
	if(curSum > n) return;
	tempAns.push_back(index);
	if((int)tempAns.size() == k) {
		if(curSum == n) {
			int facSum = 0;
			for(const int& num : tempAns) facSum += num;
			if(facSum > maxFacSum) {
				ans = tempAns;
				maxFacSum = facSum;
			}
		}
	}
	else {
		for(int i = index; i >= 1; i--) DFS(i, curSum + table[i]);
	}
	tempAns.pop_back();
}
int main() {
	scanf("%d%d%d", &n, &k, &p);
	for(int i = 0; i < MAXN; i++) table[i] = pow(i, p);
	for(int i = pow(n, 1.0/p); table[i] * k >= n; i--) DFS(i, table[i]);
	if(ans.empty()) printf("Impossible\n");
	else {
		printf("%d = ", n);
		for(int i = 0; i < k; i++) {
			printf("%d^%d%s", ans[i], p, i != k - 1 ? " + " : "\n");
		}
	}
	return 0;
}