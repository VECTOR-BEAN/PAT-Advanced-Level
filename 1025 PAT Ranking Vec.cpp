#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
constexpr int MAXN = 100;
struct Testee{
	string id;
	int score, totalRank, locRank, locNum;
	Testee(){}
	Testee(string _id, int _score, int _locNum): id(_id), score(_score), locNum(_locNum) {}
};

vector<Testee> testees;

bool cmp(Testee a, Testee b) {
	return (a.score == b.score) ? a.id <= b.id: a.score > b.score;
}

int main(){
	int n, m, score;
	string id;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &m);
		if(m == 0) continue;
		int preN = testees.size();
		for(int j = 0; j < m; j++) {
			cin >> id >> score;
			testees.push_back(Testee(id, score, i));
		}
		sort(&testees[preN], &testees[testees.size()-1]+1, cmp);
		testees[preN].locRank = 1;
		for(int j = preN+1, rank = 2; j < testees.size(); j++, rank++) {
			if(testees[j].score == testees[j-1].score) testees[j].locRank = testees[j-1].locRank;
			else testees[j].locRank = rank;
		}
	}
	sort(testees.begin(), testees.end(), cmp);
	int preScore = testees.front().score, preRank = 1, index=1;
	printf("%d\n", testees.size());
	for(auto testee: testees) {
		if(testee.score == preScore) testee.totalRank = preRank;
		else {
			testee.totalRank = index;
			preScore = testee.score;
			preRank = testee.totalRank;
		}
		printf("%s %d %d %d\n", testee.id.c_str(), testee.totalRank, testee.locNum, testee.locRank);
		index++;
	}
	return 0;
}