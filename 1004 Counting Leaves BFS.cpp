#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100;

struct Node {
    int layer;
    vector<int> son;
} tree[MAXN];

int maxLayer = 1, leaf[MAXN] = {0};

void BFS() {
    queue<Node> q;
    tree[1].layer = 1;
    q.push(tree[1]);
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
		if (node.layer > maxLayer) maxLayer = node.layer;
        if (node.son.empty()) leaf[node.layer]++;
        for(auto sonId: node.son){
        	tree[sonId].layer = node.layer + 1;
        	q.push(tree[sonId]);
        }
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0, id, num; i < M; i++) {
        scanf("%d%d", &id, &num);
        for (int j = 0, sonId; j < num; j++) {
            scanf("%d", &sonId);
            tree[id].son.push_back(sonId);
        }
    }

    BFS();

    for (int i = 1; i <= maxLayer; i++) {
        printf("%d", leaf[i]);
        if(i < maxLayer) printf(" ");
        else printf("\n");
    }
    return 0;
}