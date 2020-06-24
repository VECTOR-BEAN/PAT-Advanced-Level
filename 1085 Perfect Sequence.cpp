#include<iostream>
#include<algorithm>
using namespace std;
constexpr int MAXN = 100000;
int nums[MAXN];
int main() {
	int n, p, ans = 0; scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
	sort(nums, nums + n);
	for (int i = 0, j; i < n; i++) {
		j = upper_bound(nums + i + 1, nums + n, (long long) nums[i] * p) - nums;
		if (j - i > ans) ans = j - i;
	}
	printf("%d\n", ans);
	return 0;
}