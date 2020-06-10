#include<iostream>
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for(int div = 1, r, l, now; n / div != 0; div *= 10) {
		l = n / div / 10; now = n / div % 10; r = n % div;
		switch(now) {
		case 0: ans += l * div; break;
		case 1: ans += l * div + r + 1; break;
		default: ans += (l + 1) * div; break;
		}
	}
	printf("%d\n", ans);
	return 0;
}