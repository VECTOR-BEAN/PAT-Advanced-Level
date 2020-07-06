#include<iostream>
#include<cstring>
using namespace std;
constexpr int MAXN = 100;
int main() {
	int n, cnt = 0; scanf("%d", &n);
	double ans = 0, temp; char a[MAXN], b[MAXN];
	for(int i = 0, len, flag; i < n; i++) {
		scanf("%s", a); len = strlen(a);
		sscanf(a, "%lf", &temp); sprintf(b, "%.2f", temp);
		for(int i = 0; i < len && (flag || i == 0); i++) flag = a[i] == b[i];
		if(flag && temp <= 1000 && temp >= -1000) {
			ans += temp;
			cnt++;
		}
		else {
			printf("ERROR: %s is not a legal number\n", a);
		}
	}
	if(cnt == 0) printf("The average of 0 numbers is Undefined\n");
	else printf("The average of %d %s is %.2f\n", cnt, cnt == 1?"number":"numbers", ans / cnt);
	return 0;
}