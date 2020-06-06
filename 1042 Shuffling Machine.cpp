#include<iostream>
using namespace std;

int main() {
	int order[55], cards[54], temp[54];
	char cls[] = "SHCDJ";
	for(int i = 0; i < 55; i++) {
		scanf("%d", &order[i]);
		if(i < 54) cards[i] = i + 1;
	}
	for(int i = 0; i < order[0]; i++) {
		for(int j = 1; j < 55; j++) temp[order[j]-1] = cards[j-1];
		for(int j = 0; j < 54; j++) cards[j] = temp[j];
	}
	for(int i = 0; i < 54; i++) {
		printf("%c%d%c", cls[(cards[i]-1) / 13], (cards[i]-1) % 13 + 1,i < 53 ? ' ': '\n');
	}
	return 0;
}