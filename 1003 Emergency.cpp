#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;

const int MAXN = 500;
const int INF = 0x3f3f3f3f;
int N, M, src, dst, teams[MAXN];
int pnums[MAXN], maxTeam[MAXN];

struct Road{
	int dest, length;
	Road(){};
	Road(int dst, int len): dest(dst), length(len){}
};

vector<Road> Graph[MAXN];

void dijkstra() {
	int vis[MAXN], dist[MAXN];
	memset(vis, 0, sizeof(vis));
	fill(dist, dist+MAXN, INF);
	memset(pnums, 0, sizeof(pnums));
	memset(maxTeam, 0, sizeof(maxTeam));

	dist[src] = 0, maxTeam[src] = teams[src], pnums[src] = 1;

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
					maxTeam[road.dest] = maxTeam[u] + teams[road.dest];
					pnums[road.dest] = pnums[u];
				}
				else if(minDist + road.length == dist[road.dest]){
					pnums[road.dest] += pnums[u];
					if(maxTeam[u] + teams[road.dest] > maxTeam[road.dest]) 
						maxTeam[road.dest] = maxTeam[u] + teams[road.dest];
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
	printf("%d %d\n", pnums[dst], maxTeam[dst]);
	return 0;
}