#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;
constexpr int MAXN = 100000;
constexpr char BasicLevel = 'B';
constexpr char AdvancedLeval = 'A';
constexpr char TopLevel = 'T';
int ans[MAXN], ns[MAXN], tws[MAXN];
double scores[MAXN];
char i2s[MAXN][7];
unordered_map<string, int> s2i;
struct Testee {
	double score;
	char id[7], school[7];
	char level() { return id[0]; }
} testee;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0, idx; i < n; ++i) {
		scanf("%s%lf%s", testee.id, &testee.score, testee.school);
		for (char& ch : testee.school) ch = tolower(ch);
		if (!s2i.count(testee.school)) {
			strcpy(i2s[s2i.size()], testee.school);
			s2i[testee.school] = s2i.size()-1;
		}
		idx = s2i[testee.school]; ++ns[idx];
		if (testee.level() == BasicLevel) scores[idx] += testee.score / 1.5;
		else if (testee.level() == AdvancedLeval) scores[idx] += testee.score;
		else scores[idx] += testee.score * 1.5;
	}
	int len = s2i.size();
	for (int i = 0; i < len; ++i) tws[i] = (int) scores[i];
	for (int i = 0; i < len; ++i) ans[i] = i;
	sort(ans, ans + len, [](const int& a, const int& b)
	{ return tws[a] != tws[b] ? tws[a] > tws[b] : (ns[a] != ns[b] ? ns[a] < ns[b] : strcmp(i2s[a], i2s[b]) < 0); });
	printf("%d\n", len);
	if (len) printf("1 %s %d %d\n", i2s[ans[0]], tws[ans[0]], ns[ans[0]]);
	for (int i = 1, rank = 1; i < len; i++) {
		printf("%d %s %d %d\n", tws[ans[i]] == tws[ans[i - 1]] ? rank : rank = i + 1, i2s[ans[i]], tws[ans[i]], ns[ans[i]]);
	}
	return 0;
}
/*
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu

5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/