#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    int t = 1; //scanf("%d", &t);
    while (t--) {
        long long a, b; scanf("%lld %lld", &a, &b);

        printf("%lld\n%lld\n", gcd(a, b), lcm(a, b));
    }

    return 0;
}