#include<iostream>
using namespace std;
int main() {
	string a, b, c, d; cin >> a >> b >> c >> d;
	char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	auto between = [](char l, char r, char ch) -> bool {return ch >= l && ch <= r;};
	for(string::size_type i = 0, flag = 0; i < a.size() && i < b.size(); i++) {
		if(a[i] != b[i]) continue;
		if(!flag && between('A', 'G', a[i])) {
			printf("%s ", day[a[i] - 'A']);
			flag = 1;
		}
		else if(flag && (between('A', 'N', a[i]) || between('0', '9', a[i]))){
			printf("%02d:", between('0', '9', a[i])?a[i]-'0':a[i]-'A'+10);
			break;
		}
	}
	for(string::size_type i = 0; i < c.size() && i < d.size(); i++) {
		if(c[i] == d[i] && (between('A', 'Z', c[i])||between('a', 'z', c[i]))) {
			printf("%02d\n", (int)i);
			break;
		}
	}
	return 0;
}