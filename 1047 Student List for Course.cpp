#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
constexpr int MAXK = 2500;
vector<string> names;
vector<int> courses[MAXK + 1];
bool cmp(int i, int j) { return names[i] < names[j]; }

int main() {
	int n, k;
	scanf("%d %d", &n, &k); names.resize(n);
	for (int i = 0, count; i < n; i++) {
		cin >> names[i]; scanf("%d", &count);
		for (int j = 0, id; j < count; j++) {
			scanf("%d", &id);
			courses[id].push_back(i);
		}
	}
	for (int id = 1; id <= k; id++) {
		sort(courses[id].begin(), courses[id].end(), cmp);
		printf("%d %llu\n", id, courses[id].size());
		for (const auto& nameid : courses[id]) printf("%s\n", names[nameid].c_str());
	}
	return 0;
}