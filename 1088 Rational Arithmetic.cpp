#include<iostream>
long long GCD(long long a, long long b) { return b == 0 ? a : GCD(b, a % b); } 
void display(long long a, long long b) {
    long long gcd = GCD(a, b);
    if (gcd != 0) { a /= gcd; b /= gcd; }
    if (b < 0) { a = -a; b = -b; }
    if (b == 0) printf("Inf");
    else if (b == 1 || a == 0) printf(a < 0 ? "(%lld)" : "%lld", a);
    else if (llabs(a) < b) printf(a < 0 ? "(%lld/%lld)" : "%lld/%lld", a, b);
    else printf(a < 0 ? "(%lld %lld/%lld)" : "%lld %lld/%lld", a / b, llabs(a) % b, b);
}
int main() {
    long long a1, b1, a2, b2; scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    display(a1, b1); printf(" + "); display(a2, b2); printf(" = "); display(a1 * b2 + a2 * b1, b1 * b2); putchar('\n');
    display(a1, b1); printf(" - "); display(a2, b2); printf(" = "); display(a1 * b2 - a2 * b1, b1 * b2); putchar('\n');
    display(a1, b1); printf(" * "); display(a2, b2); printf(" = "); display(a1 * a2, b1 * b2); putchar('\n');
    display(a1, b1); printf(" / "); display(a2, b2); printf(" = "); display(a1 * b2, a2 * b1); putchar('\n');
    return 0;
}