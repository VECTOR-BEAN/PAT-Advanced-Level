#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
constexpr int MAXN = 10000;
constexpr int MAXK = 10;
int row[MAXN];
struct Stu{
	int height;
	char name[9];
} students[MAXN];
int main() {
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%s%d", students[i].name, &students[i].height);
	sort(students, students + n, [](const Stu& a, const Stu& b) 
		{return a.height != b.height ? a.height > b.height : strcmp(a.name, b.name) < 0;});
	for(int rowIndex = 0, i, j, len, m = n / k, now = 0; rowIndex < k; rowIndex++) {
		len = rowIndex == 0 ? m + n % m : m; j = len / 2; i = j - 1;
		for(int index = 0; index < len; index++) {
			row[index % 2 == 0 ? j++ : i--] = now++;
		}
		for(int index = 0; index < len; index++) 
			printf("%s%c", students[row[index]].name, index == len-1?'\n':' ');
	}
	return 0;
}