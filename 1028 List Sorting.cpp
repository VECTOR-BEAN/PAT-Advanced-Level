#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Stu{
	int id, score;
	string name;
};
int sortType;
vector<Stu> stus;
bool cmp(Stu a, Stu b) {
	if(sortType == 2 && a.name != b.name) return a.name < b.name;
	if(sortType == 3 && a.score != b.score) return a.score < b.score;
	return a.id < b.id;
}

int main() {
	int n;
	scanf("%d%d\n", &n, &sortType);
	stus.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> stus[i].id >> stus[i].name >> stus[i].score;
	}
	sort(stus.begin(), stus.end(), cmp);
	for(auto stu: stus) {
		printf("%06d %s %d\n", stu.id, stu.name.c_str(), stu.score);
	}
	return 0;
}