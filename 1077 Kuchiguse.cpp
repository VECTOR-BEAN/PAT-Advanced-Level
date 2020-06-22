#include<iostream>
#include<cstring>
using namespace std;
constexpr int MAX = 257;
char str[MAX], suffix[MAX];
int main() {
	int n, sufLen = 0; scanf_s("%d\n", &n);
	for (int i = 0, j, strLen; i < n; i++) {
		cin.getline(str, MAX); strLen = strlen(str);
		if (i == 0) {
			for (j = 0; j < strLen; j++) suffix[j] = str[strLen - j - 1];
			suffix[strLen] = '\0'; sufLen = strLen;
		}
		else {
			for (j = 0; j < sufLen && suffix[j] == str[strLen - 1 - j]; j++);
			suffix[j] = '\0'; sufLen = j;
		}
	}
	if (sufLen == 0) printf("nai");
	else for (int j = sufLen - 1; j >= 0; j--) putchar(suffix[j]);
	printf("\n");
	return 0;
}