#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
constexpr int MAXN = 100000;
int a[MAXN], b[MAXN];
int main() {
	int n; scanf("%d", &n);
	vector<int> ans;
	for(int i = 0, num; i < n; i++) {
		scanf("%d", &num);
		a[i] = b[i] = num;
	}
	sort(b, b + n);
	for(int i = 0, maximum = 0; i < n; i++) {
		if(a[i] == b[i] && a[i] > maximum) ans.push_back(a[i]);
		if(a[i] > maximum) maximum = a[i];
	}
	printf("%d%s", (int)ans.size(), ans.empty()?"\n\n":"\n");
	for(const int& num : ans) printf("%d%c", num, num == ans.back()?'\n':' ');
	return 0;
}