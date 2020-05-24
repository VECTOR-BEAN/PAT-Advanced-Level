#include<cstdio>
using namespace std;

int main(){
	int sum = 0;
	int digit=0, digits[3] = {0};
	char num;
	char mapping[10][10] = {"zero", "one", "two", 
							"three", "four", "five", 
							"six", "seven", "eight", "nine"};
	scanf("%c", &num);
	while(num != '\n'){
		sum += num - '0';
		scanf("%c", &num);
	}

	while(sum){
		digits[digit++] = sum % 10;
		sum /= 10;
	}
	if(digit == 0) printf("%s\n", mapping[0]);
	while(digit){
		printf("%s", mapping[digits[--digit]]);
		if(digit) printf(" ");
		else printf("\n");
	}
	return 0;
}