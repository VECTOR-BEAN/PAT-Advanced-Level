#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
constexpr int MAXN = 50001;
int cnt[MAXN], inAns[MAXN];
vector<int> ans;
int main() {
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 0, id; i < n; i++) {
		scanf("%d", &id); cnt[id]++;
		if(!ans.empty()) printf("%d: " , id);
		for(int j = 0; j < (int)ans.size() && j < k; j++) 
			printf("%d%c", ans[j], ans[j] == ans.back() ? '\n' : ' ');
		if(!inAns[id]) {
			bool flag1 = (!inAns[id]) && ((int) ans.size() < k || cnt[id] > cnt[ans.back()] || (cnt[id] ==  cnt[ans.back()] && id < ans.back())); 
			bool flag2 = (int) ans.size() == k && flag1;
			if(flag2) {
				inAns[ans.back()] = false;
				ans.pop_back();
			}
			if(flag1) {
				inAns[id] = true;
				ans.push_back(id);
			}
		}
		sort(ans.begin(), ans.end(), [](const int& a, const int& b)
		 {return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b]; });
	}
	return 0;
}