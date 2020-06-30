#include<iostream>
#include<sstream>
#include<vector>
#include<map>
using namespace std;
char i2s[2][13][5] = {
	{"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
	{"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}	
};
map<string, int> s2i[2];
int main() {
	int n; scanf("%d\n", &n);
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 13; j++) {
			s2i[i][i2s[i][j]] = j;
		}
	}
	for(int i = 0; i < n; i++) {
		string str; getline(cin, str);
		if(isdigit(str.front())) {
			int temp = stoi(str);
			if(temp > 13 && temp % 13 != 0) printf("%s %s\n", i2s[1][temp / 13], i2s[0][temp % 13]);
			else printf("%s\n", temp < 13 ? i2s[0][temp] : i2s[1][temp / 13]);
		}
		else {
			vector<string> temp;
			for(istringstream line(str); line >> str; temp.push_back(str));
			if(temp.size() > 1) printf("%d\n", s2i[1][temp[0]] * 13 + s2i[0][temp[1]]);
			else printf("%d\n", s2i[0].count(temp[0])?s2i[0][temp[0]]:s2i[1][temp[0]]*13);
		}
	}
	return 0;
}