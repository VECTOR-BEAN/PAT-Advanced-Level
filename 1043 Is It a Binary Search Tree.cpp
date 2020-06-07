#include<iostream>
#include<vector>
using namespace std;
bool isMirror;
vector<int> pre, post;

void getPost(int head, int tail) {
	if(head > tail) return;
	int i = head + 1, j = tail;
	if(isMirror) {
		while(i <= tail && pre[i] >= pre[head]) i++;
		while(j >  head && pre[j] <  pre[head]) j--;
	}
	else{
		while(i <= tail && pre[i] <  pre[head]) i++;
		while(j >  head && pre[j] >= pre[head]) j--;
	}
	if(i <= j) return;
	getPost(head+1, j);
	getPost(i, tail);
	post.push_back(pre[head]);
}

int main() {
	int n;
	scanf("%d", &n); pre.resize(n);
	for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
	if(n > 1) isMirror = (pre[1] < pre[0]) ? false : true;
	else isMirror = false;
	getPost(0, n-1);
	if(post.size() == n) {
		printf("YES\n");
		for(int i = 0; i < n; i++) printf("%d%c", post[i], i == n-1? '\n':' ');
	}
	else printf("NO\n");
	return 0;
}