#include<iostream>
#include<vector>
using namespace std;
vector<int> suffix, ans;
int binarySearch(int l, int r, int num) {
	int mid;
	while(l < r) {
		mid = (r - l) / 2 + l;
		if(suffix[mid] >= num) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main() {
	int n, m, tempMin = 0x3f3f3f3f;
	scanf("%d%d", &n, &m); 
	suffix.resize(n + 1); ans.resize(n + 1);
	suffix[0] = ans[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &suffix[i]);
		suffix[i] += suffix[i-1];
	}
	for(int i = 1, sub; i <= n; i++) {
		ans[i] = binarySearch(i, n, suffix[i-1] + m);
		sub = suffix[ans[i]] - suffix[i-1];
		if(sub >= m && sub < tempMin) tempMin = sub;
	}
	for(int i = 1; i <= n; i++) 
		if(suffix[ans[i]] - suffix[i-1] == tempMin) 
			printf("%d-%d\n", i, ans[i]);
	return 0;
}