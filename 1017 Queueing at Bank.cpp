#include<cstdio>
#include<algorithm>
using namespace std;

constexpr int MAXN = 10000;
constexpr int MAXK = 100;
constexpr int INF = 0x3f3f3f3f;

struct Customer{
	int arriveTime, processTime;
	Customer(){}
	Customer(int h, int m, int s, int _t): arriveTime(h*60*60+m*60+s), processTime(_t*60){}
} customer[MAXN];

int popTime[MAXK];

bool cmp(Customer a, Customer b) {
	return a.arriveTime < b.arriveTime;
}

int main() {
	int n, k;
	int h, m, s, time, totalTime = 0;
	scanf("%d%d", &n, &k);
	fill(popTime, popTime+k, 8*3600);
	for(int i = 0; i < n; i++) {
		scanf("%d:%d:%d%d", &h, &m, &s, &time);
		customer[i] = Customer(h, m, s, time);
	}
	
	sort(customer, customer+n, cmp);
	for(int i = 0; i < n; i++) {
		Customer c = customer[i];
		if(c.arriveTime > 17 * 3600) {
			n = i;
			break;
		}

		int winId = -1, minPopTime = INF;
		for (int tempWinId = 0; tempWinId < k; tempWinId++) {
			if (popTime[tempWinId] < minPopTime) {
				winId = tempWinId;
				minPopTime = popTime[tempWinId];
			}
		}
		if (winId == -1) return 0;

		if(c.arriveTime <= popTime[winId]) {
			totalTime += popTime[winId] - c.arriveTime;
			popTime[winId] += c.processTime;
		}
		else {
			popTime[winId] = c.arriveTime + c.processTime;
		}
	}
	printf("%.1f\n", (totalTime / 60.0) / n);
	return 0;
}