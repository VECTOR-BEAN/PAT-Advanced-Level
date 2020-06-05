#include<iostream>
using namespace std;
constexpr int MAXN = 1001;
int dp[MAXN][MAXN];
int main() {
	string str; getline(cin, str);
	int n = str.length(), ans = 1;
	for(int i = 0; i < n; i++) {
		dp[i][i] = 1;
		if(i < n - 1 && str[i] == str[i+1]) {
			dp[i][i+1] = 1;
			ans = 2;
		}
	}
	for(int L = 3; L <= n; L++) {
		for(int i = 0, j = L - 1; j < n; i++, j++) {
			if(str[i] == str[j] && dp[i+1][j-1] == 1) {
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}