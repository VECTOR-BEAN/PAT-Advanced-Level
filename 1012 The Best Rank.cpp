#include<cstdio>
#include<memory.h>
#include<algorithm>

using namespace std;

int nowSub, exist[1000000], query[2000];
char sub[4] = {'A', 'C', 'M', 'E'};

struct Stu{
	int id, bestSub, grade[4], rank[4];
} stu[2000];

bool cmp(Stu a, Stu b){
	return a.grade[nowSub] > b.grade[nowSub];
}

int main(){
	int N, M;
	memset(exist, -1, sizeof(exist));
	scanf("%d%d", &N, &M);

	if(N == 0) {
		for(int i=0; i<M; i++) printf("N/A\n");
		return 0;
	}

	for(int i = 0; i < N; i++){
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0 + 0.5;
	}
	for(int i = 0; i < M; i++) scanf("%d", &query[i]);

	for(nowSub = 0; nowSub < 4; nowSub++){
		sort(stu, stu + N, cmp);
		stu[0].rank[nowSub] = 1;
		for(int i = 1; i < N; i++) {
			stu[i].rank[nowSub] = (stu[i].grade[nowSub] == stu[i-1].grade[nowSub]) ? stu[i-1].rank[nowSub]: i+1;
		}
	}

	for(int i = 0; i < N; i++) {
		exist[stu[i].id] = i;
		stu[i].bestSub = 0;
		for(int sub = 1; sub < 4; sub++){
			if(stu[i].rank[sub] < stu[i].rank[stu[i].bestSub]) stu[i].bestSub = sub;
		}
	}
	for(int i = 0; i < M; i++) {
		if(exist[query[i]] == -1) printf("N/A\n");
		else printf("%d %c\n", stu[exist[query[i]]].rank[stu[exist[query[i]]].bestSub], sub[stu[exist[query[i]]].bestSub]);
	}

	return 0;
}