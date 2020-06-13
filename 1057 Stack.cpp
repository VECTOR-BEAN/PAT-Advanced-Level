#include<iostream>
#include<cstring>
#include<stack>
#define lowbit(x) ((x) & (-x))
using namespace std;
constexpr int MAXN = 100000;
int count[MAXN + 1];
stack<int> s;
void update(int x, int value) {
	for(int i = x; i <= MAXN; i += lowbit(i)) count[i] += value;
}

int getSum(int x) {
	int sum = 0;
	for(int i = x; i >= 1; i -= lowbit(i)) sum += count[i];
	return sum;
}

int binarySearch(int k){
	int l = 1, r = MAXN, mid;
	while(l < r) {
		mid = (l + r) / 2;
		if(getSum(mid) >= k) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	int n; char cmd[11]; scanf("%d", &n);
	memset(count, 0, sizeof(count));
	for(int i = 0, temp; i < n; i++) {
		scanf("%s", cmd);
		if(strcmp(cmd, "Pop") == 0 && !s.empty()) {
			printf("%d\n", s.top());
			update(s.top(), -1); s.pop();
		}
		else if(strcmp(cmd, "PeekMedian") == 0 && !s.empty()) 
			printf("%d\n", binarySearch((s.size() + 1) / 2));
		else if(strcmp(cmd, "Push") == 0) {
			scanf("%d", &temp); s.push(temp);
			update(s.top(), 1);
		}
		else printf("Invalid\n");
	}
	return 0;
}