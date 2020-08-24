#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAXN = 100;
vector<int> nodes[MAXN];
int leaves[MAXN];
int BFS(const int& root, int layer) {
    queue<int> q; 
    for(q.push(root); !q.empty(); layer++) {
        for(int len = q.size(); len-- > 0; q.pop()) {
            if(nodes[q.front()].empty()) leaves[layer]++;
            for(const int& sonId : nodes[q.front()]) q.push(sonId);
        }
    }
    return layer-1;
}
int main() {
    int n, m, maxLayer; 
    if(scanf("%d", &n) && n != 0) scanf("%d", &m);
    else return 0; // The case ends with N being 0 must NOT be processed.
    for (int i = 0, id, k; i < m && scanf("%d%d", &id, &k); i++) {
        for(int j = 0, cid; j < k && scanf("%d", &cid); j++) {
            nodes[id].push_back(cid);
        }
    }
    maxLayer = BFS(1, 1);
    for (int i = 1; i <= maxLayer; i++) {
        printf("%d%c", leaves[i], i == maxLayer?'\n':' ');
    }
    return 0;
}