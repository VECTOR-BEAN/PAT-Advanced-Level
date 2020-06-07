#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int, int> fav;
vector<int> strip, dp;
int main() {
	int n, m, l, maximum = 0;
	scanf("%d\n%d", &n, &m);
	for(int i = 1, c; i <= m; i++) {
		scanf("%d", &c);
		fav[c] = i;
	}
	scanf("%d", &l);
	strip.resize(l); dp.resize(l);
	for(int i = 0; i < l; i++) {
		scanf("%d", &strip[i]);
		if(fav[strip[i]]) dp[i] = 1;
		else dp[i] = 0;
		for(int j = 0; j < i; j++)
			if(fav[strip[i]] >= fav[strip[j]] && dp[j] >= dp[i]) 
				dp[i] = dp[j] + 1;
		if(dp[i] > maximum) maximum = dp[i];
	}
	printf("%d\n", maximum);
}