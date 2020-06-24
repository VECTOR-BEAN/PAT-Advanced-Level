#include<iostream>
#include<cstring>
constexpr int MAXN = 30;
int pos = 0, pre[MAXN], in[MAXN], post[MAXN], stk[MAXN];
void postTraversal(int preL, int preR, int inL, int inR) {
    if(preL > preR || inL > inR) return;
    int root = pre[preL], mid = inL;
    while(in[mid] != root) mid++;
    postTraversal(preL + 1, preL - inL + mid, inL, mid-1);
    postTraversal(preL - inL + mid + 1, preR, mid + 1, inR);
    post[pos++] = root;
}

int main() {
    int n; char str[5]; scanf("%d", &n);
    for(int i = 0, j = 0, k = 0, sz = 0; i < 2 * n; i++) {
        scanf("%s", str);
        if(strcmp(str, "Pop") == 0) {
            if(sz == 0) return 0;
            else in[k++] = stk[--sz];
        }
        else {
            scanf("%d", &stk[sz]);
            pre[j++] = stk[sz++];
        }
    }
    postTraversal(0, n-1, 0, n-1);
    for(int i = 0; i < n; i++) printf("%d%c", post[i], i == n-1?'\n':' ');
    return 0;
}