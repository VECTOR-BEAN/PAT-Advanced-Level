#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int maxStep, carry, curStep;
	vector<int> num, tempNum;
	for(char temp = getchar(); temp != ' '; temp = getchar()) num.push_back(temp - '0');
	for(scanf("%d", &maxStep), curStep = 0; curStep < maxStep; curStep++) {
		tempNum = num; carry = 0;
		reverse(tempNum.begin(), tempNum.end());
		if(tempNum == num) break;
		for(int i = 0, temp; i < num.size(); i++) {
			temp = num[i] + tempNum[i] + carry;
			num[i] = temp % 10;
			carry = temp / 10;
		}
		if(carry) num.push_back(carry);
	}
	for(int i = num.size() - 1; i >= 0; i--) printf("%d", num[i]);
	printf("\n%d\n", curStep);
	return 0;
}