#include<iostream>
#include<algorithm>
using namespace std;
constexpr int MAXN = 100;
int ori[MAXN], pSorted[MAXN];

int main() {
	int n, index, index2; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &ori[i]);
	for (int i = 0; i < n; i++) scanf("%d", &pSorted[i]);
	for (index = 0; index < n - 1 && pSorted[index] <= pSorted[index + 1]; index++);
	for (index2 = index + 1; index2 < n && ori[index2] == pSorted[index2]; index2++);
	if (index2 == n) {
		printf("Insertion Sort\n");
		sort(ori, ori + index + 2);
	}
	else {
		printf("Merge Sort\n"); bool flag = false;
		for (int len = 2, i; !flag; len *= 2) {
			for (i = 0; i < n && ori[i] == pSorted[i]; i++);
			flag = (i == n);
			for (i = 0; i < n; i += len) {
				if (i + len - 1 < n) sort(ori + i, ori + i + len);
				else sort(ori + i, ori + n);
			}
		}
	}
	for (int i = 0; i < n; i++) printf("%d%c", ori[i], i == n - 1 ? '\n' : ' ');
	return 0;
}