#include<iostream>
#include<vector>
using namespace std;
constexpr int MAXN = 50000;
vector<int> prime(MAXN, 1);
int main() {
	int num; scanf("%d", &num);
	prime[0] = prime[1] = 0;
	for (int i = 2; i < MAXN; i++)
		if (prime[i]) for (int j = 2 * i; j < MAXN; j += i) prime[j] = 0;
	printf("%d", num); if(num == 1) printf("=1");
	for (int base = 2, temp = num, exp; temp != 1; base++) {
		if (!prime[base] || temp % base != 0) continue;
		printf("%c", temp == num?'=':'*');
		for (exp = 0; temp % base == 0; exp++) temp /= base;
		if(exp == 1) printf("%d", base);
		else printf("%d^%d", base, exp);
	}
	printf("\n");
	return 0;
}