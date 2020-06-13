#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<int> nums[51];
vector<double> ans;
int main() {
	int n; scanf("%d", &n);
	for(int i = 1, m; i <= n; i++) {
		scanf("%d", &m);
		for(int j = 0, temp; j < m; j++) {
			scanf("%d", &temp);
			nums[i].insert(temp);
		}
	}
	int k; scanf("%d", &k);
	for(int i = 0, a, b; i < k; i++) {
		scanf("%d %d", &a, &b);
		double c = 0, t = nums[a].size();
		for(auto num : nums[b]) {
			if(nums[a].find(num) == nums[a].end()) t++;
			else c++;
		}
		ans.push_back(c/t);
	}
	for(auto res : ans) printf("%.1f%%\n", res * 100);
	return 0;
}