#include<iostream>
using namespace std;
int main(){
	int index, sum = 0, digits[3];
	char mapping[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(char num = getchar(); num != '\n'; num = getchar()) sum += num - '0';
    for(index = 0; sum != 0; sum /= 10) digits[index++] = sum % 10;
	if(index == 0) printf("%s\n", mapping[0]);
    for(int i = index - 1; i >= 0; i--) printf("%s%c", mapping[digits[i]], i == 0?'\n':' ');
	return 0;
}