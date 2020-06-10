#include<iostream>
#include<cstring>
#include<memory.h>
using namespace std;
constexpr int MAXN = 10001;
int len, hashTable[128];
char str[MAXN];
int main() {
	memset(hashTable, 0, sizeof(hashTable));
	cin.getline(str, MAXN); len = strlen(str);
	for(char temp = getchar(); temp != '\n'; temp = getchar()) 
		hashTable[temp] = 1;
	for(int i = 0; i < len; i++) if(!hashTable[str[i]]) 
		printf("%c", str[i]);
	printf("\n");
	return 0;
}