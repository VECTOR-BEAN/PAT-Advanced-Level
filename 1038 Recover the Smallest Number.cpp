#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> strs;

bool cmp(string a, string b) { return a + b < b + a;}

int main() {
	int n; string ans = "";
	scanf("%d", &n); strs.resize(n);
	for(int i = 0; i < n; i++) cin >> strs[i];
	sort(strs.begin(), strs.end(), cmp);
	for(int i = 0; i < n; i++) ans += strs[i];
	while(!ans.empty() && ans.front() == '0') ans.erase(ans.begin());
	if(ans.empty()) printf("0\n");
	else printf("%s\n", ans.c_str());
	return 0;
}