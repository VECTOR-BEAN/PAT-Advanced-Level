#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
constexpr int INF = 0x3f3f3f3f;
struct Station {
	double price, dist;
}newStation;

int main() {
	int n, now = 0;
	double cap, dist, distAvg, ans = 0, tank = 0;
	vector<Station> stations;
	scanf("%lf %lf %lf %d", &cap, &dist, &distAvg, &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &newStation.price, &newStation.dist);
		stations.push_back(newStation);
	}
	newStation.price = 0, newStation.dist = dist;
	stations.push_back(newStation);
	sort(stations.begin(), stations.end(), [](const Station& a, const Station& b) { return a.dist < b.dist; });
	if (stations.empty() || stations.front().dist != 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	double maxDist = cap * distAvg;
	while (now < n) {
		int dest = -1; double minPrice = INF;
		for (int i = now + 1; i <= n && stations[now].dist + maxDist >= stations[i].dist; i++) {
			if (stations[i].price < minPrice) {
				dest = i;
				minPrice = stations[i].price;
				if (minPrice < stations[now].price) break;
			}
		}
		if (dest == -1) break;
		double need = (stations[dest].dist - stations[now].dist) / distAvg;
		if (stations[dest].price < stations[now].price) {
			if (tank < need) {
				ans += stations[now].price * (need - tank);
				tank = 0;
			}
			else tank -= need;
		}
		else {
			ans += (cap - tank) * stations[now].price;
			tank = cap - need;
		}
		now = dest;
	}
	if (now == n) printf("%.2f\n", ans);
	else printf("The maximum travel distance = %.2f\n", stations[now].dist + maxDist);
	return 0;
}