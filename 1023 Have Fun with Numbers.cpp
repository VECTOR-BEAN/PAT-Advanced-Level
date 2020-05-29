#include<iostream>
#include<cstring>
#include<memory.h>
using namespace std;

int main() {
	int len, size = 0, carry=0, flag = 1,res[21], cnt[10];
	char bigNum[20];
	memset(cnt, 0, sizeof(cnt));
	scanf("%s", bigNum);
	len = strlen(bigNum);
	for(int i = len - 1; i >= 0; i--, size++) {
		int digit = bigNum[i] - '0';
		int temp = 2 * digit + carry;
		carry = temp / 10;
		res[size] = temp % 10;
		cnt[digit]++;
		cnt[res[size]]--;
	}
	if(carry != 0) res[size++] = carry;

	for(auto i:cnt) {
		if(i != 0 || size > len) {
			flag = 0;
			break;
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	for(int i = size-1; i >= 0; i--) {
		printf("%d", res[i]);
	}
	printf("\n");
	return 0;
}