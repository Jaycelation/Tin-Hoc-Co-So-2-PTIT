#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int checkPrime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return n > 1;
}

int check(char *s) {
    int val = 0;
    for (int i = 0; i < strlen(s); ++i) {
        char c = s[i];
        val += c - '0';
        if (i % 2 == 0) {
            if ((c - '0') % 2 != 0) {
                return 0;
            }
        } else {
            if ((c - '0') % 2 == 0) {
                return 0;
            }
        }
    }
    return checkPrime(val);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        char c[505]; scanf("%s", c);

        printf(check(c) ? "YES\n" : "NO\n");

    }
    return 0;
}