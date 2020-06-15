#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
constexpr int MAXN = 1000;
struct Mooncake {
	double weight, unitPrice;
};
vector<Mooncake> mooncakes;
int main() {
	int n; double d, ans = 0;
	scanf("%d%lf", &n, &d); mooncakes.resize(n);
	for (auto& mck : mooncakes) scanf("%lf", &mck.weight);
	for (auto& mck : mooncakes) scanf("%lf", &mck.unitPrice); 
	for (auto& mck : mooncakes)	mck.unitPrice /= mck.weight;
	sort(mooncakes.begin(), mooncakes.end(), [](const Mooncake& a, const Mooncake& b) {return a.unitPrice > b.unitPrice; });
	for (const auto& mck : mooncakes) {
		double take = (d >= mck.weight) ? mck.weight : d;
		ans += take * mck.unitPrice;
		d -= take;
	}
	printf("%.2f\n", ans);
	return 0;
}