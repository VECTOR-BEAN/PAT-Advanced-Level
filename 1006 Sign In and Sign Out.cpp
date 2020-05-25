#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Record{
	char id[15];
	int in, out;
};

bool cmpIn(Record a, Record b) {return a.in <= b.in;}

bool cmpOut(Record a, Record b)	{return a.out >= b.out;}

int main(){
	int M;
	vector<Record> records;
	scanf("%d", &M);
	for(int i=0, h, m, s; i<M; i++) {
		Record temp;
		scanf("%s", temp.id);
		scanf("%d:%d:%d", &h, &m, &s);
		temp.in = h * 3600 + m * 60 + s;
		scanf("%d:%d:%d", &h, &m, &s);
		temp.out = h * 3600 + m * 60 + s;
		records.push_back(temp);
	}
	sort(records.begin(), records.end(), cmpIn);
	printf("%s ", records.front().id);
	sort(records.begin(), records.end(), cmpOut);
	printf("%s\n", records.front().id);
}