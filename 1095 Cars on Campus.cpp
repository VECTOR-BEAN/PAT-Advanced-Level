#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int MAXN = 10000;
struct Record {
	char plate[8];
	int ts, flag; // 1 - in, 0 - out
} records[MAXN], validRec[MAXN];
char ans[MAXN][8];
map<string, int> totalTime;
int main() {
	int n, k, validN = 0, maxParkTime = -1, carNum = -1; char status[4];
	scanf("%d%d", &n, &k);
	for (int i = 0, h, m, s; i < n; i++) {
		scanf("%s %d:%d:%d %s", records[i].plate, &h, &m, &s, status);
		records[i].ts = 3600 * h + 60 * m + s;
		records[i].flag = strcmp(status, "in") == 0 ? 1 : 0;
	}
	sort(records, records + n, [](const Record& a, const Record& b)
	{return strcmp(a.plate, b.plate) == 0 ? a.ts < b.ts : strcmp(a.plate, b.plate) < 0; });
	for (int i = 1; i < n; i++) {
		const Record last = records[i - 1], now = records[i];
		if (strcmp(last.plate, now.plate) == 0 && last.flag && !now.flag) {
			validRec[validN++] = last;
			validRec[validN++] = now;
			totalTime[last.plate] += now.ts - last.ts;
		}
	}
	sort(validRec, validRec + validN, [](const Record& a, const Record& b) {return a.ts < b.ts; });
	for (int i = 0, count = 0, j = 0, h, m, s; i < k; i++) {
		scanf("%d:%d:%d", &h, &m, &s);
		for (int ts = 3600 * h + 60 * m + s; j < validN && validRec[j].ts <= ts; j++) {
			if (validRec[j].flag) count++;
			else count--;
		}
		printf("%d\n", count);
	}
	for (const auto& kv : totalTime) {
		if (kv.second > maxParkTime) {
			carNum = 0; maxParkTime = kv.second;
			strcpy(ans[carNum++], kv.first.c_str());
		}
		else if (kv.second == maxParkTime) {
			strcpy(ans[carNum++], kv.first.c_str());
		}
	}
	for (int i = 0; i < carNum; i++) printf("%s ", ans[i]);
	printf("%02d:%02d:%02d\n", maxParkTime/3600, maxParkTime % 3600 / 60, maxParkTime % 3600 % 60);
	return 0;
}