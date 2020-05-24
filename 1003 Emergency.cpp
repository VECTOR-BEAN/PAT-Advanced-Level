#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;

const int MAXN = 500;
const int INF = 0x3f3f3f3f;
int N, M, src, dst, teams[MAXN];

struct Road{
	int dest, length;
	Road(){};
	Road(int dst, int len): dest(dst), length(len){}
};

vector<Road> Graph[MAXN];

void dijkstra() {
	int vis[MAXN], dist[MAXN], pnums[MAXN], totalTeam[MAXN];
	memset(vis, 0, sizeof(vis));
	fill(dist, dist+MAXN, INF);
	memset(pnums, 0, sizeof(pnums));
	memset(totalTeam, 0, sizeof(totalTeam));

	dist[src] = 0, totalTeam[src] = teams[src], pnums[src] = 1;

	for(int i=0; i<N; i++){
		int u = -1, minDist = INF;
		for(int j=0; j<N; j++){
			if(!vis[j] && dist[j] < minDist) {
				u = j;
				minDist = dist[j];
			}
		}

		if(u == -1) return;
		vis[u] = 1;
		for(auto road: Graph[u]) {
			if(!vis[road.dest]){
				if(minDist + road.length < dist[road.dest]) {
					dist[road.dest] = minDist + road.length;
					totalTeam[road.dest] = totalTeam[u] + teams[road.dest];
					pnums[road.dest] = pnums[u];
				}
				else if(minDist + road.length == dist[road.dest]){
					pnums[road.dest] += pnums[u];
					if(totalTeam[u] + teams[road.dest] > totalTeam[road.dest]) 
						totalTeam[road.dest] = totalTeam[u] + teams[road.dest];
				}
			}
		}
	}
}

int main(){
	memset(teams, 0, sizeof(teams));
	scanf("%d%d%d%d", &N, &M, &src, &dst);
	for(int i=0; i<N; i++) scanf("%d", &teams[i]);
	for(int i=0, s, d, dis; i<M; i++) {
		scanf("%d%d%d", &s, &d, &dis);
		Graph[s].push_back(Road(d, dis));
		Graph[d].push_back(Road(s, dis));
	}
	dijkstra();
	printf("%d %d\n", pnums[dst], totalTeam[dst]);
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