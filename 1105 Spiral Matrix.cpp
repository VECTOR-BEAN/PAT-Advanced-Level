#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 10000;
int nums[MAXN], ans[MAXN];
int main() {
	int n, row, col; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &nums[i]);
	sort(nums, nums + n, [](const int& a, const int& b){return a > b;});
	for(col = sqrt(n); col > 0 && n % col != 0; col--); row = n / col;
	for(int cycle = 0, now = 0; now < n; cycle++) {
		int iMAX = row - cycle - 1, jMAX = col - cycle - 1;
		for(int j = cycle; now < n && j <= jMAX; j++) ans[cycle * col + j] = nums[now++];
		for(int i = cycle + 1; now < n && i < iMAX; i++) ans[i * col + jMAX] = nums[now++];
		for(int j = jMAX; now < n && j >= cycle; j--) ans[iMAX * col + j] = nums[now++];
		for(int i = iMAX - 1; now < n && i > cycle; i--) ans[i * col + cycle] = nums[now++];
	}
	for(int i = 0; i < n; i++) printf("%d%c", ans[i], (i + 1) % col == 0 ? '\n' : ' ');
	return 0;
}