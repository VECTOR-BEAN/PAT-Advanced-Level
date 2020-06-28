#include<iostream>
#include<queue>
using namespace std;
int n, m, l, thrhd, brain[1286][128][60], inq[1286][128][60];
struct Node {
	int x, y, z;
	Node operator+(const Node& offset) const { return { x + offset.x, y + offset.y, z + offset.z }; }
} temp, front;
Node offsets[6] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1} };

bool valid(const Node& node) {
	auto between = [](const int& lo, const int& hi, const int& num) { return num >= lo && num < hi; };
	return between(0, n, node.x) && between(0, m, node.y) && between(0, l, node.z);
}

int BFS(int x, int y, int z) {
	int cnt = 1; queue<Node> q;
	for (q.push({x, y, z}); !q.empty(); q.pop()) {
		front = q.front();
		for (const Node& offset : offsets) {
			temp = front + offset;
			if (valid(temp) && brain[temp.x][temp.y][temp.z] && !inq[temp.x][temp.y][temp.z]) {
				inq[temp.x][temp.y][temp.z] = true;
				q.push(temp); cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int ans = 0; scanf("%d%d%d%d", &n, &m, &l, &thrhd);
	for (int k = 0; k < l; k++) 
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				scanf("%d", &brain[i][j][k]);
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0, cnt; j < m; j++) {
				if (brain[i][j][k] && !inq[i][j][k]) {
					inq[i][j][k] = true;
					cnt = BFS(i, j, k);
					if (cnt >= thrhd) ans += cnt;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}