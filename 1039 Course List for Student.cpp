#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

map<string, set<int>> mp;
vector<string> query;

int main() {
	int n, m; string name;
	scanf("%d %d", &n, &m); query.resize(n);
	for(int i = 0, cid, num; i < m; i++) {
		scanf("%d %d", &cid, &num);
		for(int j = 0; j < num; j++) {
			cin >> name;
			mp[name].insert(cid);
		}
	}
	for(int i = 0; i < n; i++) cin >> query[i];
	for(auto name : query) {
		printf("%s %llu", name.c_str(), mp[name].size());
		for(auto cid : mp[name]) printf(" %d", cid);
		printf("\n");
	}
	return 0;
}