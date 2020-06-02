#include<iostream>
#include<vector>
using namespace std;
constexpr int MAXN = 200000;
constexpr int INF = 0x3f3f3f3f;
int Seq1[MAXN], Seq2[MAXN];

int main() {
	int i, j, m, n, pos;
	scanf("%d", &m);
	for(i = 0; i < m; i++) scanf("%d", &Seq1[i]);
	scanf("%d", &n);
	for(j = 0; j < n; j++) scanf("%d", &Seq2[j]);
	Seq1[m] = Seq2[n] = INF;
	i = j = 0, pos = m + n - 1;
	while(i + j < pos/2) {
		Seq1[i] < Seq2[j]?(i++):(j++); 
	}
	printf("%d\n", Seq1[i]<= Seq2[j]?Seq1[i]:Seq2[j]);
	return 0;
}