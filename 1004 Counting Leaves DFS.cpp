#include<cstdio>
#include<memory.h>
#include<vector>
using namespace std;
const int MAXN = 100;

int maxLayer = 0, count[MAXN];
vector<int> tree[MAXN];

void DFS(int rootId, int rootLayer){
	if(tree[rootId].empty()){
		if(rootLayer > maxLayer) maxLayer = rootLayer;
		count[rootLayer]++;
		return;
	}
	for(auto sonId: tree[rootId]){
		DFS(sonId, rootLayer + 1);
	}
}

int main(){
	int N, M;
	memset(count, 0, sizeof(count));
	scanf("%d%d", &N, &M);
	for(int i=0, id, num; i<M; i++){
		scanf("%d%d", &id, &num);
		for(int j=0, sonId; j<num; j++){
			scanf("%d", &sonId);
			tree[id].push_back(sonId);
		}
	}
	DFS(1, 1);
	for(int layer=1; layer<=maxLayer; layer++) {
		printf("%d", count[layer]);
		if(layer < maxLayer) printf(" ");
		else printf("\n");
	}
	return 0;
}