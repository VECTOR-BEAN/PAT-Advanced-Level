#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
constexpr int MAXN = 1e5;
int isPrime[MAXN], ans[MAXN];
int findReverseInRadix(int num, int radix) {
	int res = 0;
	vector<int> tempNum;
	do {
		tempNum.push_back(num % radix);
		num /= radix;
	} while(num != 0);
	for(int i = 0; i < tempNum.size() / 2; i++) swap(tempNum[i], tempNum[tempNum.size()-1-i]);
	for(int i = tempNum.size() - 1; i >= 0; i--) res = res * radix + tempNum[i];
	return res;
}

int main() {
	int n, d, nowAns = 0;
	fill(isPrime, isPrime+MAXN, 1);
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2; i < MAXN; i++) {
		if(isPrime[i]) {
			for(int j = 2 * i; j < MAXN; j += i) 
				isPrime[j] = 0;
		}
	}
	while(scanf("%d", &n)) {
		if(n < 0) break;
		scanf("%d", &d);
		if(isPrime[n] && isPrime[findReverseInRadix(n, d)]) ans[nowAns++] = 1;
		else ans[nowAns++] = 0;
	}
	for(int i = 0; i < nowAns; i++) {
		if(ans[i]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}