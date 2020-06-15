#include<iostream>
constexpr int MAXN = 100000;
int pos[MAXN];
void swap(int a, int b) {
	int tempPos = pos[a];
	pos[a] = pos[b];
	pos[b] = tempPos;
}
int main() {
	int n, unordered = 0, ans = 0; scanf("%d", &n);
	for(int i = 0, temp; i < n; i++) {
		scanf("%d", &temp);
		pos[temp] = i;
		if(temp != i) unordered++;
	}
	for(int k = 0; unordered > 1;) {
		if(pos[0] == 0) {
			while(k < n && pos[k] == k) k++;
			swap(0, k);
			ans++;
		}
		while(pos[0] != 0) {
			swap(0, pos[0]);
			ans++;
			unordered--;
		}
	}
	printf("%d\n", ans);
	return 0;
}