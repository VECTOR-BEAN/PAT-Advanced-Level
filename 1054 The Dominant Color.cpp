#include<iostream>
int main() {
	int n, m, color, frequency=0;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0, c; j < m; j++) {
			scanf("%d", &c);
			if(frequency == 0) {
				color = c;
				frequency++;
			}
			else if(color == c) frequency++;
			else frequency--;	
		}
	}
	printf("%d\n", color);
	return 0;
}