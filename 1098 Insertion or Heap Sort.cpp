#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 101;
int ori[MAXN], sorted[MAXN];
int main() {
	int n, idx1, idx2; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &ori[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &sorted[i]);
	for(idx1 = 1; idx1 < n && sorted[idx1] <= sorted[idx1 + 1]; idx1++);
	for(idx2 = idx1 + 1; idx2 <= n && ori[idx2] == sorted[idx2]; idx2++);
	if(idx2 > n) {
		printf("Insertion Sort\n");
		sorted[0] = sorted[idx1+1];
		int lo = 1, mid, hi = idx1;
		while(lo < hi) {
			mid = (lo + hi) / 2;
			if(sorted[mid] > sorted[0]) hi = mid;
			else lo = mid + 1;
		}
		for(int i = idx1 + 1; i > lo; i--) sorted[i] = sorted[i-1];
		sorted[lo] = sorted[0];
	}
	else {
		printf("Heap Sort\n");
		for(idx1 = n; idx1 > 1 && sorted[idx1] > sorted[1]; idx1--);
		while(idx1 > 2 && sorted[idx1] > sorted[1]) idx1--;
		swap(sorted[1], sorted[idx1]);
		for(int root = 1, gChild = 2; gChild < idx1; root = gChild, gChild *= 2) {
			if(gChild + 1 < idx1 && sorted[gChild] < sorted[gChild + 1]) gChild++;
			if(sorted[root] > sorted[gChild]) break;
			swap(sorted[root], sorted[gChild]);
		}
	}
	for(int i = 1; i <= n; i++) printf("%d%c", sorted[i], i == n ? '\n':' ');
	return 0;
}