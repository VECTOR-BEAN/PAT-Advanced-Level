#include<iostream>
#include<vector>
using namespace std;
constexpr int MAXN = 1001;
bool heap = true, flag;
int vals[MAXN];
vector<int> path;
void DFS(const int& root, const int& n) {
	path.push_back(vals[root]);
	if (2 * root > n) {
		bool flag1 = path[0] >= path[1], flag2 = flag1;
		for (size_t i = 1; i < path.size() && flag1 == flag2; ++i) {
			flag2 = path[i - 1] >= path[i];
		}
		for (size_t i = 0; i < path.size(); ++i) {
			printf("%d%c", path[i], i == path.size() - 1 ? '\n' : ' ');
		}
		if (flag1 != flag2 || flag1 != flag) heap = false;
	}
	if (2 * root + 1 <= n) DFS(2 * root + 1, n);
	if (2 * root <= n) DFS(2 * root, n);
	path.pop_back();
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &vals[i]);
	flag = vals[1] >= vals[2];
	DFS(1, n);
	if (!heap) printf("Not Heap\n");
	else printf("%s Heap\n", flag ? "Max": "Min");
	return 0;
}