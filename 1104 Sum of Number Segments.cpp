#include<iostream>
constexpr int MAXN = 100001;
int main() {
	int n; double temp = 0;
	long long ans = 0LL;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lf", &temp);
		ans += (long long) (1000 * temp) * i * (n - i + 1); 
	}
	printf("%.2f\n", ans / 1000.0);
	return 0;
}