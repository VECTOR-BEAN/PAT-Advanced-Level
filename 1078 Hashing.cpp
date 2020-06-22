#include<iostream>
#include<map>
constexpr int MAXN = 10000;
using namespace std;
int ans[MAXN];
bool isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	int m, n; scanf("%d%d", &m, &n);
	map<int, int> hashTable;
	while (!isPrime(m)) m++;
	for (int i = 0, num, pos; i < n; i++) {
		scanf("%d", &num);
		for (int j = 0; j < m; j++) {
			pos = (num + j * j) % m;
			if (hashTable[pos] == 0) {
				hashTable[pos] = num;
				break;
			}
		}
		if (num != hashTable[pos]) ans[i] = -1;
		else ans[i] = pos;
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) printf("-");
		else printf("%d", ans[i]);
		printf("%c", i == n - 1 ? '\n' : ' ');
	}
	return 0;
}