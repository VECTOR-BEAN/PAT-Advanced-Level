#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;
constexpr int MAXN = 201;
constexpr int MAXL = 10000;
int fav[MAXN], strip[MAXL], dp[MAXL];

int main() {
	int n, l, len = 0, maximum = 0;
	memset(fav, 0, sizeof(fav));
	scanf("%d\n%d", &n, &l);
	for(int i = 1, c; i <= l; i++) {
		scanf("%d", &c);
		fav[c] = i;
	}
	scanf("%d", &l);
	for(int i = 0, c; i < l; i++) {
		scanf("%d", &c);
		if(fav[c]) strip[len++] = c;
	}
	for(int i = 0; i < len; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++)
			if(fav[strip[i]] >= fav[strip[j]] && dp[i] <= dp[j]) 
				dp[i] = dp[j] + 1;
	}
	for(int i = 0; i < len; i++) if (dp[i] > maximum) maximum = dp[i];
	printf("%d\n", maximum);
}