#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

LL toRadix10(string num, LL radix) {
	LL res = 0;
	for (auto digit : num) {
		LL temp = (digit >= '0' && digit <= '9') ? (digit - '0') : (digit - 'a' + 10);
		res = res * radix + temp;
		if (res < 0) return -1; // overflow
	}
	return res;
}

LL findMinRadix(string nums) {
	LL maxNum = 0;
	for (auto digit : nums) {
		LL tempNum = (digit >= '0' && digit <= '9') ? (digit - '0') : (digit - 'a' + 10);
		if (tempNum > maxNum) maxNum = tempNum;
	}
	return maxNum + 1;
}

LL binarySearch(string a, string b, LL radix) {
	LL N1 = toRadix10(a, radix);
	LL l = findMinRadix(b), r = (l > N1 + 1) ? l : (N1 + 1), mid;
	while (l <= r) {
		mid = (l + r) / 2;
		LL N2 = toRadix10(b, mid);
		if (N1 == N2) return mid;
		else if (N2 == -1 || N1 < N2) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

int main() {
	string N1, N2;
	LL tag, radix, ans;
	cin >> N1 >> N2 >> tag >> radix;
	if (tag == 2) swap(N1, N2);
	ans = binarySearch(N1, N2, radix);
	if (ans != -1) printf("%lld\n", ans);
	else printf("Impossible\n");
	return 0;
}