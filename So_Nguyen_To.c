#include <stdio.h>
#include <math.h>

int checkPrime(long long n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return n > 1;
}

void pPrime(long long n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        int count = 0;
        while (n % i == 0) {
            count += 1;
            n /= i;
        }
        printf("%d %d\n", i, count);
    }
    if (n > 1) {
        printf("%d 1\n", n);
    }
}

int main() {
    pPrime(120);

    return 0;
}