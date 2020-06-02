#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
constexpr int INF = 0x3f3f3f3f;

struct Table {
	int endTime, vip, times;
	Table() : endTime(28800), vip(0), times(0) {}
};
struct Player {
	int arriveTime, playTime, startTime, vip;
}newPlayer;
vector<Table> tables;
vector<Player> players;

bool cmp1(Player a, Player b) { return a.arriveTime < b.arriveTime; }
bool cmp2(Player a, Player b) { return a.startTime < b.startTime; }

int nextVipIndex(int index, int n) {
	index++;
	while (index < n && !players[index].vip) index++;
	return index;
}

void allocate(int p, int t) {
	players[p].startTime = (players[p].arriveTime <= tables[t].endTime) ? tables[t].endTime : players[p].arriveTime;
	tables[t].endTime = players[p].startTime + players[p].playTime;
	tables[t].times++;
}

int main() {
	int n, k, m;
	scanf("%d", &n);
	for (int i = 0, h, m, s, p; i < n; i++) {
		scanf("%d:%d:%d %d %d\n", &h, &m, &s, &p, &newPlayer.vip);
		newPlayer.arriveTime = h * 3600 + m * 60 + s;
		if (newPlayer.arriveTime >= 75600) continue;
		newPlayer.playTime = p < 120 ? p * 60 : 7200;
		newPlayer.startTime = 75600;
		players.push_back(newPlayer);
	}
	n = players.size();
	scanf("%d %d", &k, &m);
	tables.resize(k + 1);
	for (int i = 0, id; i < m; i++) {
		scanf("%d", &id);
		tables[id].vip = 1;
	}
	sort(players.begin(), players.end(), cmp1);
	int vipId = -1, curId = 0;
	vipId = nextVipIndex(vipId, n);
	while (curId < n) {
		if (players[curId].vip && curId < vipId) {
			curId++;
			continue;
		}
		int minTid, minTidV, minEndTime, minEndTimeV;
		minTid = minTidV = -1, minEndTime = minEndTimeV = INF;
		for (int tid = 1; tid <= k; tid++) {
			if (tables[tid].endTime < minEndTime) {
				minEndTime = tables[tid].endTime;
				minTid = tid;
			}
			if (tables[tid].vip && tables[tid].endTime < minEndTimeV) {
				minEndTimeV = tables[tid].endTime;
				minTidV = tid;
			}
		}
		if (minTid == -1 || minEndTime >= 75600) break;  // if don't have a table or the earliest table ends after 21:00
		if (tables[minTid].vip && players[curId].vip) allocate(curId, minTid);
		else if (!tables[minTid].vip && !players[curId].vip) allocate(curId, minTid);
		else if (tables[minTid].vip && !players[curId].vip) {
			if (vipId < n && players[vipId].arriveTime <= tables[minTid].endTime) allocate(vipId, minTid);
			else allocate(curId, minTid);
		}
		else {
			if (minTidV != -1 && tables[minTidV].endTime <= players[curId].arriveTime) allocate(curId, minTidV);
			else allocate(curId, minTid);
		}
		while (vipId < n && players[vipId].startTime < 21 * 3600) vipId = nextVipIndex(vipId, n);
		while (curId < n && players[curId].startTime < 21 * 3600) curId++;
	}
	sort(players.begin(), players.end(), cmp2);
	for (auto player : players) {
		if (player.startTime >= 75600) break;
		printf("%02d:%02d:%02d ", player.arriveTime / 3600, player.arriveTime % 3600 / 60, player.arriveTime % 60);
		printf("%02d:%02d:%02d ", player.startTime / 3600, player.startTime % 3600 / 60, player.startTime % 60);
		printf("%.0f\n", round(((double)player.startTime - (double)player.arriveTime) / 60.0));
	}
	for (int i = 1; i <= k; i++) printf("%d%c", tables[i].times, (i != k) ? ' ' : '\n');
	return 0;
}
