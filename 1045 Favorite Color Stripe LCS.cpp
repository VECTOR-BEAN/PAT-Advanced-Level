#include<iostream>
using namespace std;
constexpr int MAXM = 201;
constexpr int MAXL = 10001;
int fav[MAXM], strip[MAXL], dp[MAXM][MAXL];

int main() {
	int N, M, L;
	scanf("%d\n%d", &N, &M); dp[0][0] = 0;
	for(int i = 1; i <= M; i++) {
		scanf("%d", &fav[i]);
		dp[i][0] = 0;
	}
	scanf("%d", &L);
	for(int i = 1; i <= L; i++) {
		scanf("%d", &strip[i]);
		dp[0][i] = 0;
	}
	for(int m = 1; m <= M; m++) {
		for(int l = 1; l <= L; l++) {
			int MAX = max(dp[m-1][l], dp[m][l-1]);
			if(strip[l] == fav[m]) dp[m][l] = MAX + 1;
			else dp[m][l] = MAX;
		}
	}
	printf("%d\n", dp[M][L]);
	return 0;
}