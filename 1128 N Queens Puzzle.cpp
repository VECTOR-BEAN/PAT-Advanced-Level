#include<iostream>
#include<memory.h>
constexpr int MAXN = 1000;
bool rows[MAXN], dia1[2 * MAXN - 1], dia2[2 * MAXN - 1];
int main() {
	int k; scanf("%d", &k);
	for(int i = 0, n, flag; i < k; i++) {
		scanf("%d", &n); flag = true;
		memset(rows, 0, sizeof(rows));
		memset(dia1, 0, sizeof(dia1));
		memset(dia2, 0, sizeof(dia2));
		for(int col = 1, row; col <= n; col++) {
			scanf("%d", &row);
			if(rows[row-1] || dia1[n + col - row - 1] || dia2[col + row - 2])
				flag = false;
			rows[row-1] = dia1[n + col - row - 1] = dia2[col + row - 2] = true;
		}
		printf("%s\n", flag ? "YES":"NO");
	}
	return 0;
}