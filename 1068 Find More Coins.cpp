#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
constexpr int MAXN = 10010;
constexpr int MAXM = 110;
int w[MAXN], dp[MAXN], choice[MAXN][MAXM];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	sort(w+1, w+n+1, [](int a, int b) {return a > b;});
	for(int i = 1; i <= n; i++) {
		for(int j = m; j >= w[i]; j--) {
			if(dp[j] <= dp[j-w[i]] + w[i]) {
				choice[i][j] = 1;
				dp[j] = dp[j-w[i]] + w[i];
			}
		}
	}
	if(dp[m] != m) { printf("No Solution\n"); return 0; }
	vector<int> arr;
	for(int v = m, i = n; v > 0; i--) {
		if(choice[i][v]) {
			arr.push_back(w[index]);
			v -= w[i];
		}
	}
	for(vector<int>::size_type i = 0; i < arr.size(); i++) {
		printf("%d%c", arr[i], i == arr.size() - 1 ? '\n' : ' ');
	}
	return 0;
}