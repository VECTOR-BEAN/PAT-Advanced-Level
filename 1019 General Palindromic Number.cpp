#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N, radix, flag = 1;
	vector<int> res;
	scanf("%d%d", &N, &radix);
	do {
		res.push_back(N % radix);
		N /= radix;
	}
	while(N != 0);
	for(int i = 0; i < res.size()/2; i++) {
		if(res[i] != res[res.size() - 1 - i]) {
			flag = 0;
			break;
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	for(int i = res.size()-1; i >= 0; i--) {
		printf("%d", res[i]);
		if(i == 0) printf("\n");
		else printf(" ");
	}
	return 0;
}