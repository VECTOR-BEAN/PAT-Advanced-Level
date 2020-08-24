#include<iostream>
constexpr int MAXN = 101;
int states[MAXN], liar[MAXN];
int main() {
	int n; bool flag = true; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &states[i]);
	for (int i = 1; i < n && flag; ++i) {
		for (int j = i + 1, len = 0; j <= n && flag; ++j, len = 0) {
			for (int k = 1; k <= n; ++k) {
				const int& idx = abs(states[k]);
				if ((states[k] < 0) != (idx == i || idx == j)) {
					liar[len++] = k;
				}
			}
			if (len == 2 && ((liar[0] == i) != (liar[1] == j))) {
				printf("%d %d\n", i, j); flag = false;
			}
		}
	}
	if (flag) printf("No Solution\n");
	return 0;
}