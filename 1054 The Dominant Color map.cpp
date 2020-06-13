#include <iostream>
#include <map>
using namespace std;
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    map<int, int> hash;
    int half = m * n / 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0, temp; j < m; j++) {
            scanf("%d", &temp);
            hash[temp]++;
            if(hash[temp] > half) {
                printf("%d", temp);
                return 0;
            }
        }
    }
    return 0;
}