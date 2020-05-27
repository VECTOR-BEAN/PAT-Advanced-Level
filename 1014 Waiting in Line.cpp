#include<cstdio>
#include<queue>
using namespace std;
constexpr int MAXN = 20;  // windows
constexpr int MAXK = 1000;  // customers
constexpr int MAXQ = 1000;  // queries

struct Window{
	int endTime, popTime;
	queue<int> customer;
	Window(): endTime(8*60), popTime(8*60){}
} windows[MAXN];

int main(){
	int n, m, k, q;
	int needTime[MAXK+1], queries[MAXQ], ans[MAXK+1];
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 1; i <= k; i++) scanf("%d", &needTime[i]);
	for(int i = 0; i < q; i++) scanf("%d", &queries[i]);
	for(int nowCustomer = 1; nowCustomer <= k; nowCustomer++) {
		if(nowCustomer <= n * m) {
			Window& win = windows[(nowCustomer-1) % n];
			win.customer.push(nowCustomer);
			if(nowCustomer <= n) win.popTime += needTime[nowCustomer];
			win.endTime += needTime[nowCustomer];
			ans[nowCustomer] = win.endTime;
		}
		else {
			int winIndex = 0, minPopTime = windows[winIndex].popTime;
			for(int winI = 1; winI < n; winI++) {
				if(windows[winI].popTime < minPopTime) {
					winIndex = winI;
					minPopTime = windows[winI].popTime;
				}
			}
			Window& win = windows[winIndex];
			win.customer.pop();
			win.customer.push(nowCustomer);
			win.popTime += needTime[win.customer.front()];
			win.endTime += needTime[nowCustomer];
			ans[nowCustomer] = win.endTime;
		}
	}
	for(int i = 0; i < q; i++) {
		if(ans[queries[i]] - needTime[queries[i]] >= 17 * 60) printf("Sorry\n");
		else printf("%02d:%02d\n", ans[queries[i]]/60, ans[queries[i]]%60);
	}
	return 0;
}