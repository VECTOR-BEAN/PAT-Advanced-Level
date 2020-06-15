#include<iostream>
#include<vector>
using namespace std;
int main(){
	int a, b, sum; scanf("%d%d", &a, &b);
	vector<int> res;
	sum = a + b;
	if(sum == 0) printf("0\n");
	if(sum < 0) printf("-");
	for(int num = abs(sum); num != 0; num /= 10) res.push_back(num % 10);
	for(int i = res.size() - 1; i >= 0; i--){
		printf("%d", res[i]);
		if(i == 0) printf("\n");
		else if(i % 3 == 0) printf(",");
	}
	return 0;
}