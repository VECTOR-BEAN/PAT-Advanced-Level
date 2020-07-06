#include<iostream>
#include<algorithm>
using namespace std;
constexpr int MAXN = 10000;
constexpr int MAXK = 100;
constexpr int INF = 0x3fffffff;
struct Player {
    int arriveTime, playTime, startTime, vip;
}players[MAXN];
struct Table {
    int endTime, vip, times;
    Table() : endTime(28800), vip(0), times(0) {}
}tables[MAXK];
void allocate(Player& player, Table& table) {
    player.startTime = player.arriveTime > table.endTime ? player.arriveTime : table.endTime;
    table.endTime = player.startTime + player.playTime;
    table.times++;
}
int nextVIP(int id, int n) { 
    for(id++; id < n && !players[id].vip; id++);
    return id;
}
int main() {
    int n, k, m;
    scanf("%d", &n);
    for (int i = 0, h, m, s, p; i < n; i++) {
        Player& player = players[i];
        scanf("%d:%d:%d %d %d\n", &h, &m, &s, &p, &player.vip);
        player.arriveTime = h * 3600 + m * 60 + s;
        player.playTime = p < 120 ? p * 60 : 7200;
        player.startTime = 75600;
    }
    scanf("%d %d", &k, &m);
    for (int i = 0, id; i < m; i++) {
        scanf("%d", &id);
        tables[id-1].vip = 1;
    }
    sort(players, players + n, [](const Player& a, const Player& b) {return a.arriveTime < b.arriveTime; });
    for (int pId = 0, vipId = nextVIP(-1, n), tId, tIdV, minEndTime, minEndTimeV; pId < n && players[pId].arriveTime < 75600;) {
        tId = tIdV = -1; minEndTime = minEndTimeV = INF;
        for (int j = 0; j < k; j++) {
            if (tables[j].endTime < minEndTime) {
                minEndTime = tables[j].endTime;
                tId = j;
            }
            if (tables[j].vip && tables[j].endTime < minEndTimeV) {
                minEndTimeV = tables[j].endTime;
                tIdV = j;
            }
        }
        if (tId == -1 || minEndTime >= 75600) break;
        if (players[pId].vip && tables[tId].vip) allocate(players[pId], tables[tId]);
        else if (!players[pId].vip && !tables[tId].vip) allocate(players[pId], tables[tId]);
        else if (players[pId].vip && !tables[tId].vip) {
            if (tIdV != -1 && tables[tIdV].endTime <= players[pId].arriveTime) allocate(players[pId], tables[tIdV]);
            else allocate(players[pId], tables[tId]);
        }
        else {
            if (vipId < n && players[vipId].arriveTime <= tables[tId].endTime) allocate(players[vipId], tables[tId]);
            else allocate(players[pId], tables[tId]);
        }
        if (players[vipId].startTime < 75600) vipId = nextVIP(vipId, n);
        while (pId < n && players[pId].startTime < 75600) pId++;
    }
    sort(players, players + n, [](const Player& a, const Player& b) { return a.startTime < b.startTime; });
    for (int i = 0; i < n && players[i].startTime < 75600; i++) {
        const Player& player = players[i];
        printf("%02d:%02d:%02d ", player.arriveTime / 3600, player.arriveTime % 3600 / 60, player.arriveTime % 60);
        printf("%02d:%02d:%02d ", player.startTime / 3600, player.startTime % 3600 / 60, player.startTime % 60);
        printf("%.0f\n", round(((double)player.startTime - (double)player.arriveTime) / 60.0));
    }
    for (int i = 0; i < k; i++) printf("%d%c", tables[i].times, (i < k - 1) ? ' ' : '\n');
    return 0;
}