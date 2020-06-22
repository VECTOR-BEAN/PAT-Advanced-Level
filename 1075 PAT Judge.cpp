#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;
constexpr int MAXN = 10001;
constexpr int MAXK = 6;
struct Stu{
	int id, perfect, show, scores[MAXK];
} students[MAXN];
int fullMark[MAXK];

bool cmp(Stu a, Stu b) {
	if(a.scores[0] != b.scores[0]) return a.scores[0] > b.scores[0];
	if(a.perfect != b.perfect) return a.perfect > b.perfect;
	return a.id < b.id;
}

int main() {
	int n, k, m; scanf("%d%d%d", &n, &k, &m);
	for(int i = 1; i <= k; i++) scanf("%d", &fullMark[i]);
	for(int i = 1; i <= n; i++) {
		memset(students[i].scores, -1, sizeof(students[i].scores));
		students[i].scores[0] = students[i].perfect = students[i].show = 0;
		students[i].id = i;
	}
	for(int i = 1, id, pid, mark; i <= m; i++) {
		scanf("%d %d %d", &id, &pid, &mark);
		Stu &stu = students[id];
		if(mark == -1 && stu.scores[pid] == -1) stu.scores[pid] = 0;
		else if(mark > stu.scores[pid]) {
			if(mark == fullMark[pid]) stu.perfect++;
			if(stu.scores[pid] != -1) stu.scores[0] -= stu.scores[pid];
			stu.show = 1; stu.scores[0] += mark; stu.scores[pid] = mark;
		}
	}
	sort(students + 1, students + n + 1, cmp); students[0] = students[1];
	for(int i = 1, rank = 1; i <= n; i++) {
		if(!students[i].show) break;
		if(students[i].scores[0] == students[i-1].scores[0]) printf("%d ", rank);
		else {printf("%d ", i); rank = i;}
		printf("%05d", students[i].id);
		for(int j = 0; j <= k; j++) {
			if(students[i].scores[j] == -1) printf(" -");
			else printf(" %d", students[i].scores[j]);
		}
		printf("\n");
	}
	return 0;
}