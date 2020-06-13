#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Record {
	char id[15];
	int in, out;
} temp;
int main() {
	int M; scanf("%d", &M);
	vector<Record> records;
	for (int i = 0, h, m, s; i < M; i++) {
		scanf("%s", temp.id);
		scanf("%d:%d:%d", &h, &m, &s);
		temp.in = h * 3600 + m * 60 + s;
		scanf("%d:%d:%d", &h, &m, &s);
		temp.out = h * 3600 + m * 60 + s;
		records.push_back(temp);
	}
	for (int flag = 0; flag < 2; flag++) {
		auto cmp = [flag](Record a, Record b) -> bool {return !flag ? a.in < b.in : a.out > b.out; };
		sort(records.begin(), records.end(), cmp);
		printf("%s%c", records.front().id, flag == 0 ? ' ' : '\n');
	}
	return 0;
}