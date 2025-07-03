#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

long long fibo[93];

void fibonacci() {
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i < 92; ++i) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

int main() {
    fibonacci();
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        long long n;
        scanf("%lld", &n);
        bool check = false;
        for (int j = 0; j < 92; ++j) {
            if (n == fibo[j]) {
                printf("YES\n");
                check = true;
                break;
            }
        }
        if (!check) {
            printf("NO\n");
        }
    }

    return 0;
}