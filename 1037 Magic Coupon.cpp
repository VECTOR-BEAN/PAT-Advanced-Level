#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> coupons, products;
int main() {
	int n, m, i, j, ans = 0;
	scanf("%d", &n); coupons.resize(n);
	for(i = 0; i < n; i++) scanf("%d", &coupons[i]);
	scanf("%d", &m); products.resize(m);
	for(j = 0; j < m; j++) scanf("%d", &products[j]);
	sort(coupons.begin(), coupons.end());
	sort(products.begin(), products.end());
	for(i = 0; i < n && i < m && coupons[i] < 0 && products[i] < 0; i++) 
		ans += coupons[i] * products[i];
	for(i = n-1, j = m-1; i >= 0 && j >= 0 && coupons[i] > 0 && products[j] > 0; i--, j--)
		ans += coupons[i] * products[j];
	printf("%d\n", ans);
	return 0;
}