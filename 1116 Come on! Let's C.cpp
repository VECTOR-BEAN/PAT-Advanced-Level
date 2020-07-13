#include<iostream>
#include<cmath>
using namespace std;
constexpr int MAXN = 10000;
int ranking[MAXN];
bool isPrime(const int& n) {
	if(n < 2) return false;
	bool flag = true;
	for(int i = 2, rt = sqrt(n); i <= rt && flag; i++) flag = (n % i != 0);
	return flag;
}
int main() {
	int n, k; scanf("%d", &n);
	for(int i = 1, id; i <= n; i++) {
		scanf("%d", &id);
		ranking[id] = i;
	}
	scanf("%d", &k);
	for(int i = 0, id; i < k; i++) {
		scanf("%d", &id); printf("%04d: ", id);
		if(ranking[id] != 0) { // if id exists
			if(ranking[id] == -1) printf("Checked\n"); // checked
			else { // first check
				if(ranking[id] == 1) printf("Mystery Award\n");
				else if(isPrime(ranking[id])) printf("Minion\n");
				else printf("Chocolate\n");
				ranking[id] = -1;
			}
		}
		else printf("Are you kidding?\n");
	}
	return 0;
}