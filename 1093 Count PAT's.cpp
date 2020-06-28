#include<iostream>
#include<cstring>
const int MAXN = 100000;
int pre[MAXN];
char str[MAXN];
int main() {
	int len, ans = 0;
	scanf("%s", str); len = strlen(str);
	for(int i = 0, count = 0; i < len; i++) {
		pre[i] = count;
		if(str[i] == 'P') count++;
	}
	for(int i = len - 1, count = 0; i >= 0; i--) {
		if(str[i] == 'T') count++;
		else if(str[i] == 'A') ans = (ans + pre[i] * count) % 1000000007;
	}
	printf("%d\n", ans);
	return 0;
}