#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
constexpr int MAXN = 40000;
constexpr int MAXM = 100;
constexpr int MAXK = 5;
struct Applicant {
	int Ge, Gi, tts, index, dreamSchools[MAXK];
} applicants[MAXN];
struct School {
	vector<int>::size_type quota;
	vector<int> admitted;
} schools[MAXM];
int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) scanf("%llu", &schools[i].quota);
	for (int i = 0; i < n; i++) {
		applicants[i].index = i;
		scanf("%d %d", &applicants[i].Ge, &applicants[i].Gi);
		applicants[i].tts = applicants[i].Ge + applicants[i].Gi;
		for (int j = 0; j < k; j++) scanf("%d", &applicants[i].dreamSchools[j]);
	}
	sort(applicants, applicants + n, [](const Applicant& a, const Applicant& b) {return a.tts == b.tts ? a.Ge > b.Ge : a.tts > b.tts; });
	for (int i = 0; i < n; i++) {
		const Applicant& applicant = applicants[i];
		for (int j = 0; j < k; j++) {
			School& school = schools[applicant.dreamSchools[j]];
			if (school.quota == 0) continue;
			else if (school.quota > school.admitted.size()) { 
				school.admitted.push_back(i); break; 
			}
			else if(applicant.tts == applicants[school.admitted.back()].tts && applicant.Ge == applicants[school.admitted.back()].Ge) { 
				school.admitted.push_back(i); break; 
			}
		}
	}
	for (int i = 0; i < m; i++) {
		vector<int>& admitted = schools[i].admitted;
		sort(admitted.begin(), admitted.end(), [](const int& a, const int& b) {return applicants[a].index < applicants[b].index; });
		for (auto& id : admitted) {
			printf("%d", applicants[id].index);
			if(id != admitted.back()) putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}