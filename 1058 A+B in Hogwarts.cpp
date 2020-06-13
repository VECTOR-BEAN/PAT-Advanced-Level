#include<iostream>
using namespace std;
struct Currency {
	int Galleon, Sickle, Knut;
	Currency operator+(Currency other) {
		Currency ans;
		ans.Knut = Knut + other.Knut; 
		ans.Sickle = Sickle + other.Sickle + ans.Knut / 29; ans.Knut = ans.Knut % 29;
		ans.Galleon = Galleon + other.Galleon + ans.Sickle / 17; ans.Sickle = ans.Sickle % 17;
		return ans;
	}
} a, b, ans;

int main() {
	scanf("%d.%d.%d %d.%d.%d", &a.Galleon, &a.Sickle, &a.Knut, &b.Galleon, &b.Sickle, &b.Knut);
	ans = a + b;
	printf("%d.%d.%d\n", ans.Galleon, ans.Sickle, ans.Knut);
	return 0;
}