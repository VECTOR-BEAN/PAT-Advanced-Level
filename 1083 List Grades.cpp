#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Stu{
	int grade;
	char name[12], id[12];
} stu;
vector<Stu> students;
int binarySearch(int lo, int hi, int tar){
	int mid;
	while(lo < hi) {
		mid = (lo + hi) / 2;
		if(students[mid].grade <= tar) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}
int main() {
	int n, lo, hi, start; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s%s%d", stu.name, stu.id, &stu.grade);
		students.push_back(stu);
	}
	scanf("%d%d", &lo, &hi);
	sort(students.begin(), students.end(), [](const Stu& a, const Stu& b){return a.grade > b.grade;});
	start = binarySearch(0, students.size()-1, hi);
	if(students[start].grade < lo) printf("NONE\n");
	for(int i = start; students[i].grade >= lo; i++) {
		printf("%s %s\n", students[i].name, students[i].id);
	}
	return 0;
}