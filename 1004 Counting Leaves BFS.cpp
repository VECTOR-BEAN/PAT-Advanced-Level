#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int MAXN = 100;

struct Node {
    int layer;
    vector<int> son;
};

Node tree[MAXN];
int leaf[MAXN] = {0};
int nowLayer = 1;

void BFS() {
    queue<Node> q;
    q.push(tree[1]);
    while (!q.empty()) {
        Node n = q.front(), son;
        q.pop();
        vector<int> sonVec = n.son;
		if (n.layer != nowLayer) nowLayer++;
        if (sonVec.size() == 0) {  // if it is a leaf
            leaf[nowLayer]++;
        }
        for (int i = 0; i < sonVec.size(); i++) {
            son = tree[sonVec[i]];
            son.layer = n.layer + 1;
            q.push(son);
        }
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    // case with N being 0 mustn't be processed
    if (N == 0) return 0;  
    // else
    tree[1].layer = 1;
    for (int i = 0, id, k; i < M; i++) {
        scanf("%d %d", &id, &k);
        for (int j = 0, temp; j < k; j++) {
            scanf("%d", &temp);
            tree[id].son.push_back(temp);
        }
    }

    BFS();

    for (int i = 1; i < nowLayer; i++) {
        printf("%d ", leaf[i]);
    }
    printf("%d", leaf[nowLayer]);
    return 0;
}