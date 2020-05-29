#include<iostream>
#include<sstream>
#include<set>
#include<unordered_map>
using namespace std;
constexpr int MAXM = 1000;
struct Query {
	int type;
	string content;
} query[MAXM];

unordered_map<string, set<int>> lib[5];

int main() {
	int n, m;
	string key;
	scanf("%d\n", &n);
	for (int i = 0, id; i < n; i++) {
		scanf("%d\n", &id);
		for (int j = 0; j < 5; j++) {
			getline(cin, key);
			if(j == 2) {
				string keyword;
				istringstream keywords(key);
				while (keywords >> key) lib[j][key].insert(id);
			}
			else {
				lib[j][key].insert(id);
			}
		}
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d: ", &query[i].type);
		getline(cin, query[i].content);
	}
	for(int i = 0; i < m; i++) {
		printf("%d: %s\n", query[i].type, query[i].content.c_str());
		set<int>& cur = lib[query[i].type - 1][query[i].content];
		if(cur.empty()) printf("Not Found\n");
		else for(auto id:cur) printf("%07d\n", id);
	}
	return 0;
}