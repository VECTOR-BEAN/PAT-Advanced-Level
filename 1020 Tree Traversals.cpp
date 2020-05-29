#include<cstdio>
#include<map>
using namespace std;
constexpr int MAXN = 30;
int in[MAXN], post[MAXN];
map<int, int> tree;
void buildTree(int index, int inL, int inR, int postL, int postR) {
	if(inL > inR || postL > postR) return;
	int i;
	for(i = inL; i <= inR && in[i] != post[postR]; i++);
	tree[index] = post[postR];
	buildTree(2*index, inL, i-1, postL, postL - 1 + i - inL);
	buildTree(2*index + 1, i+1, inR, postL - inL + i, postR - 1);
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &post[i]);
	for(int i = 0; i < n; i++) scanf("%d", &in[i]);
	buildTree(1, 0, n-1, 0, n-1);
	auto it = tree.begin();
	for(int i = tree.size() - 1; i >= 0; i--, it++) {
		printf("%d%c", it->second, (i == 0)?'\n':' ');
	}
	return 0;
}