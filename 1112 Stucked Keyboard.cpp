#include<iostream>
#include<map>
using namespace std;
map<char, bool> stucked, hasOutput; 
int main() {
	int k, cnt = 1; char pre = '\0'; string str;
	cin >> k >> str; str += pre;
	for(const char& ch : str) {
		if(ch == pre) cnt++;
		else {
			if(cnt % k == 0 && !stucked.count(pre)) stucked[pre] = true;
			else if(cnt % k != 0) stucked[pre] = false;
			cnt = 1; pre = ch;
		}
	}
	for(const char& ch : str) {
		if(!stucked[ch] || hasOutput[ch]) continue;
		putchar(ch); hasOutput[ch] = true;
	}
	putchar('\n');
	for(auto it = str.cbegin(); it != str.cend(); ++it) {
		putchar(*it);
		if(stucked[*it]) it = it + k - 1;
	}
	putchar('\n');
	return 0;
}