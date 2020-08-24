#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
struct Ans {
	int c, d;
} ans[10000];
unordered_map<int, bool> gender;
unordered_map<int, unordered_set<int>> relation;
int main() {
	int n, m, k; char p1[6], p2[6]; scanf("%d%d", &n, &m);
	for (int i = 0, a, b; i < m; ++i) {
		scanf("%s%s", p1, p2);
		gender[a = abs(atoi(p1))] = !isdigit(p1[0]);
		gender[b = abs(atoi(p2))] = !isdigit(p2[0]);
		relation[a].insert(b); relation[b].insert(a);
	}
	scanf("%d", &k);
	for (int i = 0, a, b, len = 0; i < k; ++i, len = 0) {
		scanf("%s%s", p1, p2); a = abs(atoi(p1)); b = abs(atoi(p2));
		for (const int& c : relation[a]) {
			if (gender[a] != gender[c] || c == b) continue;
			for (const int& d : relation[b]) {
				if (gender[b] != gender[d] || d == a) continue;
				if (relation[c].count(d)) ans[len++] = { c, d };
			}
		}
		sort(ans, ans + len, [](const Ans& a, const Ans& b) {return a.c == b.c ? a.d < b.d : a.c < b.c; });
		printf("%d\n", len);
		for_each(ans, ans + len, [](const Ans& t) { printf("%04d %04d\n", t.c, t.d); });
	}
	return 0;
}
// 吐槽
// test case 中只有9个人
