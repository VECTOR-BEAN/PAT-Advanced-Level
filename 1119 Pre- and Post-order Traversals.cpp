#include<iostream>
constexpr int MAXN = 30;
int now = 0, pre[MAXN], pst[MAXN], ans[MAXN];
bool flag = true;
void genTree(const int& preLo, const int& preHi, const int& pstLo, const int& pstHi) {
	if(preLo > preHi || pstLo > pstHi) return;
	if(preLo == preHi && pstLo == pstHi) ans[now++] = pre[preLo];
	for(int rtidx = pstLo, len; rtidx < pstHi; rtidx++) {
		// loop until find the root of first subtree
		// whose index is also the last index of first subtree
		if(pst[rtidx] != pre[preLo + 1]) continue; 
		// if the root of first subtree is found
		if(rtidx == pstHi - 1) flag = false; // if this subtree is the only subtree
		len = rtidx - pstLo; // last index - first index of the array pst
		genTree(preLo + 1, preLo + 1 + len, pstLo, rtidx);  // left subtree
		ans[now++] = pre[preLo]; // fill in the answer
		genTree(preLo + 2 + len, preHi, rtidx + 1, pstHi - 1); // right subtree
		break;
	}
}
int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for(int i = 0; i < n; i++) scanf("%d", &pst[i]);
	genTree(0, n-1, 0, n-1);
	printf("%s\n", flag ? "Yes" : "No");
	for(int i = 0; i < n; i++) printf("%d%c", ans[i], i == n - 1 ? '\n':' ');
	return 0;
}