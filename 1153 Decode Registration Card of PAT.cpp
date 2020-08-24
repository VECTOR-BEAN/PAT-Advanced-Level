#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
constexpr int MAXN = 10000;
struct Testee {
	char level;
	int site, date, id, score;
} testee[MAXN];
unordered_map<int, unordered_map<int, int>> date;
unordered_map<int, pair<int, int>> site;
unordered_map<int, vector<int>> level;
bool cmp(const int& idxa, const int& idxb) {
	const Testee& a = testee[idxa], & b = testee[idxb];
	if (a.score != b.score) return a.score > b.score;
	else if (a.site != b.site) return a.site < b.site;
	else return a.date != b.date ? a.date < b.date : a.id < b.id;
}
int main() {
	int n, q; scanf("%d%d%*c", &n, &q);
	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		Testee& t = testee[i];
		scanf("%c%3d%6d%3d%d%*c", &t.level, &t.site, &t.date, &t.id, &t.score);
	}
	for (int i = 0; i < n; ++i) {
		const Testee& t = testee[i];
		level[int(t.level)].push_back(i);
		++site[t.site].first;
		site[t.site].second += t.score;
		++date[t.date][t.site];
	}
	for (int i = 1, type, term; i <= q && scanf("%d%*c", &type); ++i) {
		switch (type) {
		case 1:
			printf("Case %d: %d %c\n", i, type, term = (int)getchar());
			sort(level[term].begin(), level[term].end(), cmp);
			for (const int& idx : level[term]) {
				const Testee& t = testee[idx];
				printf("%c%03d%06d%03d %d\n", t.level, t.site, t.date, t.id, t.score);
			}
			if (level[term].empty()) printf("NA\n");
			break;
		case 2:
			scanf("%d", &term); printf("Case %d: %d %03d\n", i, type, term);
			if (!site.count(term)) printf("NA\n");
			else printf("%d %d\n", site[term].first, site[term].second);
			break;
		case 3:
			scanf("%d", &term); printf("Case %d: %d %06d\n", i, type, term);
			copy(date[term].begin(), date[term].end(), back_inserter(v));
			sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
			{ return a.second != b.second ? a.second > b.second : a.first < b.first; });
			for (const pair<int, int>& kv : v) printf("%03d %d\n", kv.first, kv.second);
			if (v.empty()) printf("NA\n");
			v.clear();  break;
		default:
			printf("NA\n");
		}
	}
	return 0;
}