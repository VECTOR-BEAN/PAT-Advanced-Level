#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
constexpr int MAXK = 1000;
unordered_set<int> goods;
unordered_map<int, unordered_set<int>> incompatible;
int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 0, v1, v2; i < n && scanf("%d%d", &v1, &v2); ++i) {
		incompatible[v1].insert(v2);
		incompatible[v2].insert(v1);
	}
	for (int query = 0, k; query < q && scanf("%d", &k); ++query) {
		bool flag = true; goods.clear();
		for (int i = 0, val; i < k && scanf("%d", &val); ++i) goods.insert(val);
		for (const auto& kv : incompatible) {
			if (goods.count(kv.first)) {
				for (const int& good : kv.second) {
					if (goods.count(good)) { flag = false; break; }
				}
			}
			if (!flag) break;
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}