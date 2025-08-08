#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

long long fib[93] = {0};

void fibo() {
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= 92; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }

}

int main() {
    int t = 1;
    // scanf("%d", &t);
    fibo();
    for (int k = 1; k <= t; ++k) {
        int n; scanf("%d", &n);

        long long a[n+1][n+1];

        int left = 0, right = n-1, top = 0, bot = n-1;
        int val = 0;
        while (val < n * n) {
            //Trai qua phai
            for (int i = left; i <= right && val <= n*n; ++i) {
                a[top][i] = fib[val++];
            }
            top++;

            //Tren xuong duoi
            for (int i = top; i <= bot && val <= n*n; ++i) {
                a[i][right] = fib[val++];
            }
            right--;

            //Phai qua trai
            for (int i = right; i >= left && val <= n*n; i--) {
                a[bot][i] = fib[val++];
            }
            bot--;
            //Duoi len tren
            for (int i = bot; i >= top && val <= n*n; i--) {
                a[i][left] = fib[val++];
            }
            left++;
        }
        //printf("Test %d:\n", k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%lld ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
