#include<iostream>
#include<vector>
using namespace std;
char units[5][10] = { "", " Shi", " Bai", " Qian", " Wan", " Shi", " Bai", " Qian", " Yi"};
char mp[10][10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
bool print(const vector<int>& nums, bool flag) {
	// flag1: has current vector output or not
	// flag2: whether output "ling" first before output next number
	bool flag1 = false, flag2 = false;
	for (int i = nums.size() - 1; i >= 0; i--) {
		if (nums[i] == 0) flag2 = true;
		else {
			if (flag || flag1) putchar(' ');
			if (flag2) printf("%s ", mp[0]);
			printf("%s%s", mp[nums[i]], units[i]);
			flag1 = true; flag2 = false;
		}
	}
	return flag1;
}
int main() {
	int n, Ng = 0; scanf("%d", &n);
	vector<int> nums[3];
	if (n == 0) printf("%s", mp[0]);
	else if (n < 0) printf("Fu ");
	for (n = abs(n); n > 0; n /= 10) {
		if (nums[Ng].size() == 4) Ng++;
		nums[Ng].push_back(n % 10);
	}
	for (int i = Ng; i >= 0; i--) {
		if (print(nums[i], i == Ng ? false:true)) {
			printf("%s", groupUnits[i]);
		}
	}
	putchar('\n');
	return 0;
}