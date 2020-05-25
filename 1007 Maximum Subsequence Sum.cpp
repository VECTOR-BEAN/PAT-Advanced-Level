#include<cstdio>
using namespace std;
const int MAXN = 10000;

int opt[MAXN], pre[MAXN], nums[MAXN];

int main(){
	int N, sum = 0, flag = 0;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d", &nums[i]);
		flag = (nums[i] >= 0) ? 1:flag;
		sum += nums[i];
		if(sum <= nums[i]) {
			opt[i] = pre[i] = nums[i];
			sum = nums[i];
		}
		else{
			opt[i] = sum;
			pre[i] = pre[i-1];
		}
	}
	if(!flag) {
		printf("0 %d %d\n", nums[0], nums[N-1]);
	}
	else {
		int maxI = 0;
		for(int i=0; i<N; i++) {
			if(opt[i] > opt[maxI]) maxI = i;
		}
		printf("%d %d %d\n", opt[maxI], pre[maxI], nums[maxI]);
	}
	return 0;
}