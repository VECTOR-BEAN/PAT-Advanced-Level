#include<cstdio>
#include<vector>
using namespace std;

int main(){
	int a, b, sum;
	vector<int> res;
	scanf("%d%d", &a, &b);
	sum = a + b;
	if(sum == 0){
		printf("0");
	}
	else if(sum < 0) {
		printf("-");
		sum *= -1;
	}
	while(sum){
		res.push_back(sum % 10);
		sum /= 10;
	}
	for(int i = res.size() - 1; i >= 0; i--){
		printf("%d", res[i]);
		if(i % 3 == 0 && i != 0) printf(",");
	}
	printf("\n");
	return 0;
}