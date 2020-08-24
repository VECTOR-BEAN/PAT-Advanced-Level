#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;
set<int> lonely;
unordered_map<int, int> couple;
int main() {
	int n, m; scanf("%d", &n);
	for(int i = 0, c1, c2; i < n; i++) {
		scanf("%d%d", &c1, &c2);
		couple[c1] = c2;
		couple[c2] = c1;
	}
	scanf("%d", &m); 
	for(int i = 0, id; i < m; i++) {
		scanf("%d", &id);
		if(!couple.count(id) || !lonely.count(couple[id])) lonely.insert(id);
		else lonely.erase(couple[id]);
	}
	printf("%llu\n", lonely.size());
	for(const int& id : lonely) printf("%05d%c", id, id == *lonely.crbegin()?'\n':' ');
	return 0;
}