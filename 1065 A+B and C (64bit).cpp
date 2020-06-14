#include<iostream>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	long long a, b, c, ans;
	for(int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		ans = a + b;
		if(a > 0 && b > 0 && ans <= 0) printf("Case #%d: true\n", i);
		else if(a < 0 && b < 0 && ans >= 0) printf("Case #%d: false\n", i);
		else if(ans > c) printf("Case #%d: true\n", i);
		else printf("Case #%d: false\n", i);
	}
	return 0;
}