#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool palindromic(vector<int> num) {
	int len = num.size();
	for(int i = 0; i < len/2; i++) {
		if(num[i] != num[len-1-i]) return false;
	}
	return true;
}

int main() {
	int maxStep, curStep = 0, carry = 0;
	vector<int> num, tempNum;
	string rawNum;
	cin >> rawNum >> maxStep;
	for(int i = rawNum.size() - 1; i >= 0; i--) {
		num.push_back(rawNum[i] - '0');
	}
	while(!palindromic(num) && curStep < maxStep) {
		curStep++;
		tempNum = num;
		reverse(tempNum.begin(), tempNum.end());
		for(int i = 0, len = num.size(), temp; i < len; i++) {
			temp = num[i] + tempNum[i] + carry;
			num[i] = temp % 10;
			carry = temp / 10;
		}
		if(carry != 0) {
			num.push_back(carry);
			carry = 0;
		}
	}
	for(int i = num.size() - 1; i >= 0; i--) printf("%d", num[i]);
	printf("\n%d\n", curStep);
	return 0;
}