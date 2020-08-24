#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<string> winners;
int main() {
	int m, n, s; char name[21];
	scanf("%d%d%d", &m, &n, &s);
	for(int i = 1; i <= m; i++) {
		scanf("%s", name);
		if(i != s) continue;
		if(winners.count(name)) s = s + 1;
		else {
			printf("%s\n", name);
			winners.insert(name);
			s += n;
		}
	}
	if(winners.empty()) printf("Keep going...\n");
	return 0;
}