#include<cstdio>
#include<memory.h>
using namespace std;

int main(){
	int count = 0;
	double res[1001], coe;
	memset(res, 0, sizeof(res));
	for(int i=0, terms; i<2; i++){
		scanf("%d", &terms);
		for(int j = 0, exp; j < terms; j++){
			scanf("%d %lf", &exp, &coe);
			res[exp] += coe;
		}
	}
	for(int i=0; i<1001; i++) if(res[i]) count++;
	printf("%d", count);
	for(int exp= 1000; exp>=0; exp--){
		if(res[exp]) printf(" %d %.1f", exp, res[exp]);
	}
	printf("\n");
	return 0;
}

// positive coefficient plus negative coefficient could be zero