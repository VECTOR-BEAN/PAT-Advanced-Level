#include<iostream>
bool friendId[40];
int main() {
	int n, cnt = 0; scanf("%d", &n);
	for(int i = 0, num, ans = 0; i < n; i++, ans = 0) {
		for(scanf("%d", &num); num != 0; num /= 10) ans += (num % 10);
		if(!friendId[ans]) cnt++;
		friendId[ans] = true;
	}
	printf("%d\n", cnt);
	for(int i = 0; i < 40; i++) {
		if(!friendId[i]) continue;
		printf("%d%c", i, --cnt?' ':'\n');
	}
	return 0;
}