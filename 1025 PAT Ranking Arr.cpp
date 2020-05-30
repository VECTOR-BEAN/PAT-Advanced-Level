#include<iostream>
#include<algorithm>
using namespace std;
constexpr int MAXNM = 30000;
struct Testee{
	string id;
	int score, totalRank, locRank, locNum;
} testee[MAXNM+1];

bool cmp(Testee a, Testee b) {
	return (a.score == b.score) ? a.id <= b.id: a.score > b.score;
}

int main(){
	int n, m, curN = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &m);
		int preN = curN;
		for(int j = 0; j < m; j++) {
			cin >> testee[curN].id >> testee[curN].score;
			testee[curN].locNum = i+1;
			curN++;
		}
		sort(&testee[preN], &testee[curN], cmp);
		testee[preN].locRank = 1;
		for(int j = preN+1, rank = 2; j < curN; j++, rank++) {
			if(testee[j].score == testee[j-1].score) testee[j].locRank = testee[j-1].locRank;
			else testee[j].locRank = rank;
		}
	}
	sort(&testee[0], &testee[curN], cmp);
	Testee pre = testee[0];
	pre.totalRank = 1;
	printf("%d\n", curN);
	for(int i = 0; i < curN; i++) {
		if(testee[i].score == pre.score) testee[i].totalRank = pre.totalRank;
		else testee[i].totalRank = i + 1;
		printf("%s %d %d %d\n", testee[i].id.c_str(), testee[i].totalRank, testee[i].locNum, testee[i].locRank);
		pre = testee[i];
	}
	return 0;
}