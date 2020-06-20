#include<iostream>
#include<string>
using namespace std;
int main() {
	string str; cin >> str;
	int coeLen, dotPos;
	coeLen = str.find('E');
	dotPos = 1 + stoi(str.substr(coeLen + 1));
	if (str.front() == '-') printf("-");
	if (dotPos <= 0) {
		// case 0: dotPos <= 0
		// +1.2345E-3 --> 0.0012345
		printf("0.");
		while (dotPos++ < 0) printf("0");
		for (int i = 0; i < coeLen; i++) {
			if (isdigit(str[i])) printf("%c", str[i]);
		}
	}
	else if (dotPos < coeLen - 2) {
		// case 1: dotPos > 0 && dotPos < coeLen - 2;
		// +1.2345E+2 --> 123.45
		int i = 0, cnt = 0;
		while (i < coeLen) {
			if (cnt == dotPos) {
				printf(".");
				cnt++;
			}
			else if (isdigit(str[i])) {
				printf("%c", str[i]);
				i++; cnt++;
			}
			else i++;
		}
	}
	else {
		// case 2: dotPos > 0 && dotPos >= coeLen - 2;
		// +1.2345E+4 --> 12345
		int i = 0, cnt = 0;
		while (cnt < dotPos) {
			if (i < coeLen && isdigit(str[i])) {
				printf("%c", str[i]);
				i++; cnt++;
			}
			else if (i >= coeLen) {
				printf("0");
				i++; cnt++;
			}
			else i++;
		}
	}
	printf("\n");
	return 0;
}