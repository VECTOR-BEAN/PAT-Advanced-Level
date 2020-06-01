#include<iostream>
char mp[14] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

int main() {
	int nums[3];
	for(int i = 0; i < 3; i++) scanf("%d", &nums[i]);
	printf("#");
	for(auto num:nums) printf("%c%c", mp[num/13], mp[num%13]);
	printf("\n");
	return 0;
}
/*
15 43 71
#123456
*/