#include<iostream>
#include<algorithm>
using namespace std;
constexpr int MAXN = 100001;
int sum[MAXN];
int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &sum[i]);
	sort(sum + 1, sum + n + 1);
	for(int i = 1; i <= n; i++) sum[i] += sum[i-1];
	printf("%d %d\n", n % 2, sum[n] - 2 * sum[n/2]);
	return 0;
}