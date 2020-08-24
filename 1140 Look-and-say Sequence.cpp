#include<iostream>
#include<cstring>
char str[100000], ans[100000];
int main() {
	int n, sz=1; scanf("%s%d", str, &n);
	for(int i = 1, len; i < n; ++i) {
		len = sz; sz = 0;
		for(int j = 0, k; j < len; j = k) {
			for(k = j; k < len && str[k] == str[j]; ++k);
			ans[sz++] = str[j];
			ans[sz++] = (k - j)+'0';
		}
		memcpy(str, ans, sz);
	}
	for(int i = 0; i < sz; ++i) putchar(str[i]);
	putchar('\n');
	return 0;
}