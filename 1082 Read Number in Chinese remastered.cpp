#include<iostream>
char groupUnits[3][10] = { "", " Wan", " Yi" };
char units[5][10] = { "", " Shi", " Bai", " Qian" };
char mp[10][10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
int main() {
	int n, len = 0, digits[10]; scanf("%d", &n);
	if (n == 0) printf("%s", mp[0]);
	else if (n < 0) printf("Fu ");
	for (n = abs(n); n > 0; n /= 10) digits[len++] = n % 10;
	for (int i = len - 1, flag1= 0, flag2 = 0, flag3 = 0; i >= 0; i--) {
		// flag1 : whether already outputs
		// flag2 : whether print "ling" first before print next number
		// flag3 : whether the group is valid or not
		const int& num = digits[i];
		if (num == 0) flag2 = true;
		else {
			if (flag1) putchar(' ');
			if (flag2) printf("%s ", mp[0]);
			printf("%s%s", mp[num], units[i % 4]);
			flag1 = true; flag2 = false; flag3 = true;
		}
		if (i % 4 == 0 && flag3) {
			flag3 = false;
			printf("%s", groupUnits[i / 4]);
		}
	}
	putchar('\n');
	return 0;
}