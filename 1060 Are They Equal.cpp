#include<iostream>
using namespace std;
void findPow(string& str, int& pow, string::size_type sig) {
	while (!str.empty() && str.front() == '0') str.erase(str.begin());
	if (str.empty()) { pow = 0;	return;	}
	if (str.front() == '.') {
		str.erase(str.begin());
		for (pow = 0; !str.empty() && str.front() == '0'; pow--) str.erase(str.begin());
		if (str.empty()) pow = 0;
	}
	else {
		pow = str.find('.');
		if (pow == -1) pow = str.size();
		else str.erase(pow, 1);
	}
	// format string
	if(str.size() < sig) str.insert(str.end(), sig - str.size(), '0');
	if(str.size() > sig) str.erase(str.begin() + sig, str.end());
}
int main() {
	int sig, powa, powb; string a, b;
	scanf("%d", &sig); cin >> a >> b;
	findPow(a, powa, sig); findPow(b, powb, sig);
	if(a == b && powa == powb) printf("YES 0.%s*10^%d\n", a.c_str(), powa);
	else printf("NO 0.%s*10^%d 0.%s*10^%d\n", a.c_str(), powa, b.c_str(), powb);
	return 0;
}