#include<iostream>
#include<memory.h>
constexpr int MAXF = 500;
int counts[MAXF+1];
int main() {
	int n, value, faceValue;
	memset(counts, 0, sizeof(counts));
	scanf("%d %d", &n, &value);
	for(int i = 0; i < n; i++) {
		scanf("%d", &faceValue);
		counts[faceValue]++;
	}
	for(faceValue = 1; faceValue <= MAXF; faceValue++) {
		if(value == 2 * faceValue && counts[faceValue] >= 2) break;
		else if(value != 2 * faceValue && value - faceValue <= MAXF 
			&& counts[faceValue] && counts[value - faceValue]) break;
	}
	if(faceValue <= MAXF) printf("%d %d\n", faceValue, value - faceValue);
	else printf("No Solution\n");
	return 0;
}