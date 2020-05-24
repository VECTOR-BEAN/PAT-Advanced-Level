#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;

const int MAXN = 500;
const int INF = 0x3f3f3f3f;
int N, M, src, dst, teams[MAXN];
int pathNum = 0, maxTeam = 0;

struct Road{
	int dest, length;
	Road(){};
	Road(int _dest, int _dist): dest(_dest), length(_dist){}
};

vector<int> pre[MAXN];
vector<int> path, tempPath;
vector<Road> Graph[MAXN];

void dijkstra() {

	/* init */
	int vis[MAXN], dist[MAXN];
	memset(vis, 0, sizeof(vis));
	fill(dist, dist+MAXN, INF);
	dist[src] = 0;

	/* find the nearest city */
	for(int i=0; i<N; i++){
		int u = -1, minDist = INF;
		for(int j=0; j<N; j++){
			if(!vis[j] && dist[j] < minDist) {
				u = j;
				minDist = dist[j];
			}
		}

		if(u == -1) return;  // if all cities are visited
		vis[u] = 1;
		for(auto road: Graph[u]) {
			if(!vis[road.dest]){
				if(minDist + road.length < dist[road.dest]) {
					dist[road.dest] = minDist + road.length;
					pre[road.dest].clear();
					pre[road.dest].push_back(u);
				}
				else if(minDist + road.length == dist[road.dest]){
					pre[road.dest].push_back(u);
				}
			}
		}
	}
}

void DFS(int v){
	tempPath.push_back(v);
	if(v == src) {
		pathNum++;
		int teamNum = 0;
		for(auto city: tempPath) teamNum += teams[city];
		if(teamNum > maxTeam) {
			maxTeam = teamNum;
			path = tempPath;
		}
	}
	else{
		for(auto city: pre[v]) {
			DFS(city);
		}
	}
	tempPath.pop_back();
}

int main(){
	scanf("%d%d%d%d", &N, &M, &src, &dst);
	for(int i=0; i<N; i++) scanf("%d", &teams[i]);
	for(int i=0, s, d, dis; i<M; i++) {
		scanf("%d%d%d", &s, &d, &dis);
		Graph[s].push_back(Road(d, dis));
		Graph[d].push_back(Road(s, dis));
	}
	dijkstra();
	DFS(dst);
	printf("%d %d\n", pathNum, maxTeam);
	return 0;
}

/* 
sample input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
sample output
2 4
*/