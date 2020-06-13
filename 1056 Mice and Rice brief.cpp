#include<iostream>
constexpr int MAXN = 1000;
int weight[MAXN], order[MAXN], ranking[MAXN];
int main() {
	int np, ng; scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; i++) scanf("%d", &weight[i]);
	for(int i = 0; i < np; i++) scanf("%d", &order[i]);
	for(int size = np, group; size > 0; size = group) {
		if(size == 1) { ranking[order[0]] = 1; break; }
		group = size % ng == 0 ? size / ng : size / ng + 1;
		for(int i = 0, k = 0, maxId; i < size; i += ng) {
			maxId = order[i];
			for(int j = 0; j < ng && i + j < size; j++) {
				ranking[order[i + j]] = group + 1;
				if(weight[order[i + j]] > weight[maxId]) maxId = order[i + j];
			}
			order[k++] = maxId; 
		}	
	}
	for(int i = 0; i < np; i++) printf("%d%c", ranking[i], i == np - 1 ? '\n' : ' ');	
	return 0;
}