#include<iostream>
#include<memory.h>
using namespace std;
int main() {
	int sz = 0, flag = 1, carry = 0, num[21], hashTable[10];
	memset(hashTable, 0, sizeof(hashTable));
	for(char tempNum = getchar(); tempNum != '\n'; tempNum = getchar()) num[sz++] = tempNum - '0';
	for(int i = sz - 1, d; i >= 0; i--) {
		d = num[i];
		hashTable[num[i]]++;
		num[i] = (d * 2 + carry) % 10;
		carry = (d * 2 + carry) / 10;
		hashTable[num[i]]--;
	}
	for(auto i:hashTable) if(i != 0 || carry != 0) flag = 0;
	printf("%s\n", flag == 1?"Yes":"No");
	if(carry) printf("%d", carry);
	for(int i = 0; i < sz; i++) printf("%d", num[i]);
	printf("\n");
	return 0;
}