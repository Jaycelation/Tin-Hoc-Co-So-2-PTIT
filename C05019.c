#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int p[401] = {0};

int checkPrime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return n > 1;
}

void prime() {
    int cnt = 0;
    int i = 2;
    while (cnt < 401) {
        if (checkPrime(i)) {
            p[cnt++] = i;
        }
        i++;
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    prime();
    for (int k = 1; k <= t; ++k) {
        int n; scanf("%d", &n);

        int a[n+1][n+1];

        int left = 0, right = n-1, top = 0, bot = n-1;
        int val = 0;
        while (val < n * n) {
            //Trai qua phai
            for (int i = left; i <= right && val <= n*n; ++i) {
                a[top][i] = p[val++];
            }
            top++;

            //Tren xuong duoi
            for (int i = top; i <= bot && val <= n*n; ++i) {
                a[i][right] = p[val++];
            }
            right--;

            //Phai qua trai
            for (int i = right; i >= left && val <= n*n; i--) {
                a[bot][i] = p[val++];
            }
            bot--;
            //Duoi len tren
            for (int i = bot; i >= top && val <= n*n; i--) {
                a[i][left] = p[val++];
            }
            left++;
        }
        printf("Test %d:\n", k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
