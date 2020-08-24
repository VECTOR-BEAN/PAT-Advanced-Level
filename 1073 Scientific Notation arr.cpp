#include<iostream>
constexpr int MAXN = 10000;
char str[MAXN];
int main() {
	int len = 0, coeLen = 0, dotPos = 0;
	bool negative = getchar() == '-';
	for(char temp = getchar(); temp != '\n'; temp = getchar()) {
		if(temp == 'E') coeLen = len;
		else if(temp == '.') continue;
		else str[len++] = temp;
	}
	str[len] = '\0'; dotPos = 1 + atoi(str+coeLen);
	if(negative) putchar('-');
	if(dotPos <= 0) {
		printf("0."); while(dotPos++ < 0) putchar('0');
		for(int i = 0; i < coeLen; i++) putchar(str[i]);
	}
	else{
		len = coeLen > dotPos ? coeLen : dotPos;
		for(int i = 0; i < len; i++) {
			if(i == dotPos) putchar('.');
			putchar(i < coeLen ? str[i] : '0');
		}
	}
	putchar('\n');
	return 0;
}