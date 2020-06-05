#include<iostream>
#include<cstring>
using namespace std;
struct Stu {
	char name[11], id[11];
	int grade;
}newStu, male, female;

void assign(Stu& a, Stu b) {
	strcpy(a.name, b.name);
	strcpy(a.id, b.id);
	a.grade = b.grade;
}

int main() {
	int n; char gender;
	male.grade = 101, female.grade = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %c %s %d", newStu.name, &gender, newStu.id, &newStu.grade);
		if (gender == 'F' && newStu.grade > female.grade) assign(female, newStu);
		else if (gender == 'M' && newStu.grade < male.grade) assign(male, newStu);
	}
	if (female.grade == -1) printf("Absent\n");
	else printf("%s %s\n", female.name, female.id);
	if (male.grade == 101) printf("Absent\n");
	else printf("%s %s\n", male.name, male.id);
	if (female.grade == -1 || male.grade == 101) printf("NA\n");
	else printf("%d\n", female.grade - male.grade);
	return 0;
}