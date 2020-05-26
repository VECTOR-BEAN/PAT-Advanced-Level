#include<cstdio>

int main(){
	char bet[3] = {'W', 'T', 'L'}, res[3];
	double ans = 1;
	for(int i=0; i<3; i++){
		double max = 0, temp;
		for(int j=0; j<3; j++){
			scanf("%lf", &temp);
			if(temp > max) {
				max = temp;
				res[i] = bet[j];
			}
		}
		ans *= max;
	}
	for(auto i:res){
		printf("%c ", i);
	}
	printf("%.2f\n", 2*(ans*0.65-1));
	return 0;
}