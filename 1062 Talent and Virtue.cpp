#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Man{
	int id, talent, virtue, tier;
} temp;
bool cmp(Man a, Man b) {
	if(a.tier != b.tier) return a.tier < b.tier;
	if(a.virtue + a.talent != b.virtue + b.talent) return a.virtue + a.talent > b.virtue + b.talent;
	if(a.virtue != b.virtue) return a.virtue > b.virtue;
	return a.id < b.id;
}
int main() {
	int n, l, h; scanf("%d%d%d", &n, &l, &h);
	vector<Man> men;
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d", &temp.id, &temp.virtue, &temp.talent);
		if(temp.virtue < l || temp.talent < l) continue;
		if(temp.virtue >= h && temp.talent >= h) temp.tier = 1;
		else if(temp.virtue >= h && temp.talent < h) temp.tier = 2;
		else if(temp.virtue < h && temp.talent < h && temp.virtue >= temp.talent) temp.tier = 3;
		else temp.tier = 4;
		men.push_back(temp);
	}
	sort(men.begin(), men.end(), cmp);
	printf("%d\n", (int)men.size());
	for(auto man : men) printf("%08d %d %d\n", man.id, man.virtue, man.talent);
	return 0;
}