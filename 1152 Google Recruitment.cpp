#include<iostream>
#include<cmath>
constexpr int MAXL = 1000;
int num[MAXL];
bool isPrime(const int& val) {
	if(val < 2) return false;
	for(int i = 2, n = sqrt(val); i <= n; ++i) {
		if(val % i == 0) return false;
	}
	return true;
}
int main() {
	int l, k, ans = 0, flag = false; scanf("%d%d", &l, &k);
	for(int i = 0; i < l; ++i) scanf("%1d", &num[i]);
	for(int i = 0; i + k <= l; ++i, ans = 0) {
		for(int j = 0; j < k; ++j) ans = ans * 10 + num[i + j];
		if((flag = isPrime(ans))) break;
	}
	if(!flag) printf("404\n");
	else printf("%0*d\n", k, ans);
	return 0;
}