#include<cstdio>
using namespace std;

int main(){
	int N, newFloor, nowFloor = 0, sum = 0;
	scanf("%d", &N);
	for(int i=0, sub; i<N; i++){
		scanf("%d", &newFloor);
		sub = newFloor - nowFloor;
		if(sub >= 0) sum += sub * 6 + 5;
		else sum += sub * -4 + 5;
		nowFloor = newFloor;
	}
	printf("%d\n", sum);
	return 0;
}