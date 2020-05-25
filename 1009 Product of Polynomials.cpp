#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXK = 10;

struct Term {
	int exp;
	double coe;
	Term() {}
	Term(int _exp, double _coe) : exp(_exp), coe(_coe) {}
};

bool cmp(Term a, Term b) {
	return a.exp >= b.exp;
}

int main() {
	vector<Term> poly[3];
	vector<Term>::iterator it;
	for (int i = 0, k; i < 2; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int exp; double coe;
			scanf("%d%lf", &exp, &coe);
			poly[i].push_back(Term(exp, coe));
		}
	}
	for (auto a : poly[0]) {
		for (auto b : poly[1]) {
			Term product = Term(a.exp + b.exp, a.coe * b.coe);
			for (it = poly[2].begin(); it != poly[2].end(); it++) {
				if(it->exp == product.exp) {
					it->coe += product.coe;
					break;
				}
			}
			if (it == poly[2].end()) poly[2].push_back(product);
		}
	}

	for (auto it = poly[2].begin(); it != poly[2].end(); it++) {
		if (it->coe == 0) poly[2].erase(it--);
	}

	sort(poly[2].begin(), poly[2].end(), cmp);
	printf("%d", poly[2].size());
	for (auto term : poly[2]) {
		printf(" %d %.1f", term.exp, term.coe);
	}
	printf("\n");

	return 0;
}