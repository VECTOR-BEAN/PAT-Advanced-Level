#include<iostream>
#include<string>
using namespace std;
int main() {
	int n; string str; scanf("%d", &n);
	for(int i = 0, a, b, num; i < n && cin >> str; i++) {
		a = stoi(str.substr(0, str.size()/2));
		b = stoi(str.substr(str.size()/2));
		num = stoi(str);
		if(a == 0 || b == 0) printf("No\n");
		else printf("%s\n", num % (a * b) == 0 ? "Yes":"No");
	}
	return 0;
}