#include<iostream>
using namespace std;
int GCD(int a, int b) {	return b == 0 ? abs(a) : GCD(b, a % b); }
int main() {
	int n, numerator = 0, denominator = 1, integer = 0; scanf("%d", &n);
	for (int i = 0, gcd, up, down; i < n; i++) {
		scanf("%d/%d", &up, &down); gcd = GCD(down, denominator);
		numerator = numerator * (down / gcd) + up * (denominator / gcd);
		denominator = denominator * (down / gcd);
		integer += numerator / denominator;
		numerator %= denominator;
		gcd = GCD(numerator, denominator);
		numerator /= gcd; denominator /= gcd;
	}
	if (integer == 0 && numerator == 0) printf("0\n");
	else if (integer != 0 && numerator != 0) printf("%d %d/%d\n", integer, numerator, denominator);
	else if (integer == 0) printf("%d/%d\n", numerator, denominator);
	else printf("%d\n", integer);
	return 0;
}