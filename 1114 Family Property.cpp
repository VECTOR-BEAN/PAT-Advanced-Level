#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
constexpr int MAXN = 1000;
struct Person {
	int id, dad, mom, sets, area;
	vector<int> kids;
} persons[MAXN];
struct Answer {
	int id, m;
	double sets, area;
} answers[MAXN];
map<int, int> parent, mp;
int Find(const int& x) {
	if (parent[x] == parent[parent[x]]) return parent[x];
	int root; vector<int> path;
	for (root = x; root != parent[root]; root = parent[root]) path.push_back(root);
	for (const int& node : path) parent[node] = root;
	return root;
}
void Union(const int& a, const int& b) {
	if (a == -1 || b == -1) return;
	int roota = Find(a);
	int rootb = Find(b);
	if (roota != rootb) parent[rootb] = parent[roota];
}
int main() {
	int n, cnt = 0; scanf("%d", &n);
	for (int i = 0, k; i < n; i++) {
		Person& p = persons[i];
		scanf("%d%d%d%d", &p.id, &p.dad, &p.mom, &k);
		parent[p.id] = p.id;
		if(p.dad != -1) parent[p.dad] = p.dad;
		if(p.mom != -1) parent[p.mom] = p.mom;
		for (int j = 0, kid; j < k; j++) {
			scanf("%d", &kid);
			parent[kid] = kid;
			p.kids.push_back(kid);
		}
		scanf("%d%d", &p.sets, &p.area);
	}
	for (int i = 0; i < n; i++) {
		const Person& p = persons[i];
		Union(p.id, p.dad);
		Union(p.id, p.mom);
		for (const int& kid : p.kids) Union(p.id, kid);
	}
	for (const auto& kv : parent) {
		const int root = Find(kv.first);
		if (!mp.count(root)) {
			answers[cnt].id = kv.first;
			mp[root] = cnt++;
		}
		else if (kv.first < answers[mp[root]].id) answers[mp[root]].id = kv.first;
		answers[mp[root]].m++;
	}
	for (int i = 0; i < n; i++) {
		const Person& p = persons[i];
		const int root = Find(p.id);
		answers[mp[root]].sets += p.sets;
		answers[mp[root]].area += p.area;
	}
	for (int i = 0; i < cnt; i++) {
		Answer& ans = answers[i];
		ans.sets /= ans.m;
		ans.area /= ans.m;
	}
	sort(answers, answers + n, [](const Answer& a, const Answer& b) {return a.area != b.area ? a.area > b.area : a.id < b.id; });
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		const Answer& ans = answers[i];
		printf("%04d %d %.3f %.3f\n", ans.id, ans.m, ans.sets, ans.area);
	}
	return 0;
}