#include<iostream>
#include<memory.h>
using namespace std;
int hashF(const char& ch) {
	if(isupper(ch)) return ch - 'A' + 10;
	else if(islower(ch)) return ch - 'a' + 10;
	else if(isdigit(ch)) return ch - '0';
	else return 37;
}
int main() {
	int hashcode, hashTable[38];
	string a, b; cin >> a >> b;
	memset(hashTable, 0, sizeof(hashTable));
	for(const char& ch:b) hashTable[hashF(ch)] = true; 
	for(const char& ch:a) {
		hashcode = hashF(ch);
		if(!hashTable[hashcode]) {
			putchar(islower(ch)?ch - 'a' + 'A' : ch);
			hashTable[hashcode] = true;
		}
	}
	putchar('\n');
	return 0;
}