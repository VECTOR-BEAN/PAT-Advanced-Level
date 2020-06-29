#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int n, maxn; vector<int> ans, tempAns;
	scanf("%d", &n); maxn = sqrt(n) + 1;
	for(int i = 2, tempN; i <= maxn; i++) {
		if(n % i == 0) {
			tempAns.clear(); tempN = n;
			for(int j = i; j <= maxn && tempN % j == 0; j++) {
				tempAns.push_back(j);
				tempN /= j;
			}
			if(tempAns.size() > ans.size()) ans = tempAns;
		}
	}
	if(ans.empty())	printf("1\n%d\n", n);
	else {
		printf("%llu\n", ans.size());
		for(const int& i : ans) printf("%d%c", i, i==ans.back() ? '\n' : '*');
	}
	return 0;
}