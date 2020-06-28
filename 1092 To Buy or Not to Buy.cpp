#include<iostream>
#include<cstring>
int hashTable[256];
char str[1000];
int main() {
	int lena, lenb, ans = 0; 
	scanf("%s", str); lena = strlen(str);
	for(int i = 0; i < lena; i++) hashTable[(int)str[i]]++;
	scanf("%s", str); lenb = strlen(str);
	for(int i = 0; i < lenb; i++) hashTable[(int)str[i]]--;
	for(const int& cnt : hashTable) if(cnt < 0) ans -= cnt;
	if(ans) printf("No %d\n", ans);
	else printf("Yes %d\n", lena - lenb);
	return 0;
}