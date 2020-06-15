#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string, int> hashMap;
bool isCharacter(char& a) {
	auto between = [a](char l, char h) {return a >= l && a <= h;};
	if(between('A', 'Z')) a = a - 'A' + 'a';
	if(between('A', 'Z') || between('a', 'z') || between('0', '9')) return true;
	else return false;
}
int main() {
	int maximum = 0; string str = "";
	for(char temp = getchar(); true; temp = getchar()) {
		if(isCharacter(temp)) str += temp;
		else if(!str.empty()){
			hashMap[str]++;
			str.clear();
		}
		if(temp == '\n') break;
	}
	for(const auto& kv : hashMap) {
		if(kv.second > maximum) {
			str = kv.first;
			maximum = kv.second;
		}
		else if(kv.second == maximum && kv.first < str) str = kv.first; 
	}
	printf("%s %d\n", str.c_str(), maximum);
	return 0;
}