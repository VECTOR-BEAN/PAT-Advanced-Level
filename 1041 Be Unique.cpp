#include<iostream>
#include<vector>
using namespace std;
vector<int> nums, hashTable(10001, 0);

int main() {
	int n, index;
	scanf("%d", &n); nums.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
		hashTable[nums[i]]++;
	}
	for(index = 0; index < n && hashTable[nums[index]] != 1; index++);
	if(index == n) printf("None\n");
	else printf("%d\n", nums[index]);
	return 0;
}