#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	string str, a, b; cin >> str;
	str.insert(0, 4 - str.length(), '0');
	do {
		a = b = str;
		sort(a.begin(), a.end(), [](char a, char b) {return a > b;});
		sort(b.begin(), b.end(), [](char a, char b) {return a < b;});
		str = to_string(stoi(a) - stoi(b));
		str.insert(0, 4 - str.length(), '0');
		printf("%s - %s = %s\n", a.c_str(), b.c_str(), str.c_str());
	}
	while (str != "6174" && str != "0000");
	return 0;
}