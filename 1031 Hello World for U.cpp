#include<iostream>
#include<string>
using namespace std;

int main() {
	int n1, n2, n;
	string str;
	getline(cin, str);
	n = str.size();
	for(n2 = 3; n2 <= n; n2++) {
		if((n - n2 + 2) % 2 == 0) {
			n1 = (n - n2 + 2) / 2;
			if(n1 <= n2) break;
		}
	}
	for(int i = 0; i < n1 - 1; i++) {
		printf("%c", str[i]);
		for(int j = 0; j < n2 - 2; j++) printf(" ");
		printf("%c\n", str[n-1-i]);
	}
	for(int i = n1 - 1; i < n1+n2-1; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
}