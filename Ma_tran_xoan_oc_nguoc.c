#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long fib[93];
void fibo() {
    fib[0] = 0;
    fib[1] = fib[2] = 1;
    for (int i = 3; i < 93; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}


int main() {
    int t;
    scanf("%d", &t);
    fibo();
    while (t--) {
        int n; scanf("%d", &n);

        long long a[100][100] = {0};

        long long reva[100][100] = {0};

        int val = 1, top = 0, bot = n - 1, left = 0, right = n - 1;
    
        while (val <= n * n) {
            for (int i = left; i <= right && val <= n*n; ++i) {
                a[top][i] = fib[val++];
            }
            top++;

            for (int i = top; i <= bot && val <= n*n; ++i) {
                a[i][right] = fib[val++];
            }
            right--;

            for (int i = right; i >= left && val <= n*n; i--) {
                a[bot][i] = fib[val++];
            }
            bot--;

            for (int i = bot; i >= top && val <= n*n; i--) {
                a[i][left] = fib[val++];
            }
            left++;
        }
        
        val = n*n, top = 0, bot = n-1, left = 0, right = n-1;
        while (val >= 1) {
            for (int i = left; i <= right && val >= 1; ++i) {
                reva[top][i] = val--;
            }
            top++;

            for (int i = top; i <= bot && val >= 1; ++i) {
                reva[i][right] = val--;
            }
            right--;

            for (int i = right; i >= left && val >= 1; i--) {
                reva[bot][i] = val--;
            }
            bot--;

            for (int i = bot; i >= top && val >= 1; i--) {
                reva[i][left] = val--;
            }
            left++;

        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", reva[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}