#include<iostream>
#include<memory.h>
constexpr int MAXN = 201;
bool hashTable[MAXN], conductive[MAXN][MAXN];
int main() {
	int n, m, k; scanf("%d%d", &n, &m);
	for(int i = 0, v1, v2; i < m; i++) {
		scanf("%d%d", &v1, &v2);
		conductive[v1][v2] = conductive[v2][v1] = true;
	}
	scanf("%d", &k);
	for(int i = 0, k2, front, back; i < k; i++) {
		scanf("%d", &k2); front = 0;
		bool flag = (k2 == n + 1); 
		for(int j = 0, pre; j < k2; j++, pre = back) {
			scanf("%d", &back);
			hashTable[back] = true;
			if(j > 0 && flag) flag = conductive[pre][back];
			if(!front) front = back;
		}
		for(int j = 1; j <= n && flag; j++) flag = hashTable[j];
		flag = (flag && front == back);
		printf("%s\n", flag ? "YES":"NO");
		memset(hashTable, 0, sizeof(hashTable));
	}
	return 0;
}