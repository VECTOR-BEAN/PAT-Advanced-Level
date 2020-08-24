#include<iostream>
constexpr int MAXNLEN = 10001;
int ropes[MAXNLEN];
int main() {
	int n, ans, minLen = 0x3fffffff; scanf("%d", &n);
	for(int i = 0, length; i < n; i++) {
		scanf("%d", &length);
		ropes[length]++;
		if(length < minLen) minLen = length;
	}
	ans = minLen; ropes[minLen]--;
	for(int length = minLen; length < MAXNLEN; length++) {
		for(int i = 0; i < ropes[length]; i++) {
			ans = (ans + length) / 2;
		}
	}
	printf("%d\n", ans);
	return 0;
}