#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
using namespace std;
constexpr int MAXN = 1001;
int inq[MAXN];
vector<int> Graph[MAXN];
struct User{
    int id, layer;
    User() = default;
    User(int _id, int _layer): id(_id), layer(_layer){}
};
int BFS(const int& src, const int& maxLevel) {
    int ans = -1; inq[src] = 1;
    queue<User> users;
    for(users.push(User(src, 0)); !users.empty(); users.pop()) {
        const User& user = users.front();
        if(user.layer > maxLevel) break;
        ans++;
        for(const auto& childId : Graph[user.id]) {
            if(!inq[childId]) {
                inq[childId] = 1;
                users.push(User(childId, user.layer + 1));
            }
        }
    }
    return ans;
}
int main() {
    int n, l, q; scanf("%d%d", &n, &l);
    for(int i = 1, m; i <= n; i++) {
        scanf("%d", &m);
        for(int j = 0, master; j < m; j++) {
            scanf("%d", &master);
            Graph[master].push_back(i);
        }
    }
    scanf("%d", &q);
    for(int i = 0, src; i < q; i++) {
        scanf("%d", &src);
        memset(inq, 0, sizeof(inq));
        printf("%d\n", BFS(src, l));
    }
    return 0;
}