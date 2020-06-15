#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, a, b, digits[4]; scanf("%d", &n);
	auto to_arr = [](int n, int arr[]) {for (int i = 0; i < 4; i++, n/=10) arr[i] = n % 10; };
	auto to_int = [](int& n, int arr[]) {for (int i = 3; i >= 0; i--) n = n * 10 + arr[i];	};
	do {
		to_arr(n, digits); a = b = 0;
		sort(digits, digits + 4, [](int a, int b) {return a < b; }); to_int(a, digits);
		sort(digits, digits + 4, [](int a, int b) {return a > b; }); to_int(b, digits);
		n = a - b; printf("%04d - %04d = %04d\n", a, b, n);
	} while (n != 0 && n != 6174);
	return 0;
}