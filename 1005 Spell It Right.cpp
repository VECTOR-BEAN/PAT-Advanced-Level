#include<iostream>
char mp[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main(){
	int maxDigit, sum = 0, ans[3];
	for(char num = getchar(); num != '\n'; num = getchar()) sum += num - '0';
    for(maxDigit = 0; sum != 0; sum /= 10) ans[maxDigit++] = sum % 10;
	if(maxDigit == 0) printf("%s\n", mp[0]);
    for(int i = maxDigit - 1; i >= 0; i--) printf("%s%c", mp[ans[i]], i == 0?'\n':' ');
	return 0;
}