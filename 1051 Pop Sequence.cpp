#include<iostream>
constexpr int MAX = 1001;
using namespace std;
int stack[MAX], ans[MAX];
int main() {
	int cap, n, k;	
	scanf("%d %d %d", &cap, &n, &k); ;
	for(int i = 0, cur, sz; i < k; i++) {
		cur = 1; sz = 0; ans[i] = 1;
		for(int j = 0, num; j < n; j++) {
			scanf("%d", &num);
			while(cur <= num) stack[sz++] = cur++;
			if(sz <= cap && sz > 0 && stack[sz-1] == num) sz--;
			else ans[i] = 0;
		}
	}
	for(int i = 0; i < k; i++) printf("%s\n", ans[i]? "YES":"NO");
	return 0;
}