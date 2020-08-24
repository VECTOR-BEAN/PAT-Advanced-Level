#include<iostream>
constexpr int MAXD = 1002;
constexpr int iterMAX = 10;
int ori[MAXD], rev[MAXD];
bool isPal(int num[], int len) {
	bool flag = true;
	for (int i = 0; i < len / 2 && flag; i++) flag = num[i] == num[len - 1 - i];
	return flag;
}
int main() {
	int len = 0, iterNum = 0;
	for (char ch = getchar(); ch != '\n'; ch = getchar()) rev[len++] = ch - '0';
	for (int i = 0; i < len; i++) ori[i] = rev[len - i - 1];
	for (int& it = iterNum, carry = 0; it < iterMAX && !isPal(ori, len); it++) {
		for (int i = 0; i < len; i++) printf("%d", rev[i]);
		printf(" + ");
		for (int i = 0; i < len; i++) printf("%d", ori[i]);
		printf(" = ");
		for (int i = 0, temp; i < len; i++) {
			temp = ori[i] + rev[i] + carry;
			ori[i] = temp % 10;
			carry = temp / 10;
		}
		if (carry) ori[len++] = carry--;
		for (int i = 0; i < len; i++) rev[i] = ori[len - i - 1];
		for (int i = 0; i < len; i++) printf("%d", rev[i]);
		printf("\n");
	}
	if (iterNum == iterMAX) printf("Not found in %d iterations.\n", iterMAX);
	else {
		for (int i = 0; i < len; i++) printf("%d", rev[i]);
		printf(" is a palindromic number.\n");
	}
	return 0;
}