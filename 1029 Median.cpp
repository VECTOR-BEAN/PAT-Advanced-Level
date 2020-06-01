#include<iostream>
#include<vector>
using namespace std;
vector<int> nums[2];

int main() {
	int i, j, n;
	for(i = 0; i < 2; i++) {
		scanf("%d", &n);
		nums[i].resize(n);
		for(j = 0; j < n; j++) scanf("%d", &nums[i][j]);
	}
	i = j = 0, n = nums[0].size() + nums[1].size() - 1;
	while(i + j < n/2) {
		(nums[0][i] < nums[1][j])?(i++):(j++); 
	}
	printf("%d\n", nums[0][i] <= nums[1][j]?nums[0][i]:nums[1][j]);
	return 0;
}