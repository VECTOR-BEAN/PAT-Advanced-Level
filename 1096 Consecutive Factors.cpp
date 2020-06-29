#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n, maxn, ans = 0, len = 0; 
	scanf("%d", &n); maxn = sqrt(n) + 1;
	for(int i = 2, j, tempN; i <= maxn; i++) {
		if(n % i != 0) continue;
		for(j = i, tempN = n; j <= maxn && tempN % j == 0; j++) tempN /= j;
		if(j - i > len) {
			ans = i;
			len = j - i;
		}
	}
	if(len == 0) printf("1\n%d\n", n);
	else {
		printf("%d\n", len);
		for(int i = 0; i < len; i++) printf("%d%c", ans + i, i == len-1?'\n':'*');
	}
	return 0;
}