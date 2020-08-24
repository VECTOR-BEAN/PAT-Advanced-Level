#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
constexpr int MAXN = 10000;
struct Stu{
	int opa{-1}, mid{-1}, fin{-1}, g{-1};
};
char name[21];
string ans[MAXN];
unordered_map<string, Stu> mp;
int main() {
	int p, m, n, len = 0; scanf("%d%d%d", &p, &m, &n);
	for(int i = 0; i < p && scanf("%s", name); i++) scanf("%d", &mp[name].opa);
	for(int i = 0; i < m && scanf("%s", name); i++) scanf("%d", &mp[name].mid);
	for(int i = 0; i < n && scanf("%s", name); i++) scanf("%d", &mp[name].fin);
	for(auto &kv : mp) {
		if(kv.second.opa < 200) kv.second.g = 0;
		else kv.second.g = (kv.second.mid > kv.second.fin ? 0.4 * (double)kv.second.mid + 0.6 * (double)kv.second.fin : (double)kv.second.fin) + 0.5;
		if(kv.second.g >= 60) ans[len++] = kv.first; 
	}
	sort(ans, ans + len, [&len](const string &a, const string &b) { return mp[a].g == mp[b].g ? a < b : mp[a].g > mp[b].g; });
	for_each(ans, ans + len, [](const string &s) { printf("%s %d %d %d %d\n", s.c_str(), mp[s].opa, mp[s].mid, mp[s].fin, mp[s].g); });
	return 0;
}