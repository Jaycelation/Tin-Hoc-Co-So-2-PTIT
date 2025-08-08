#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int t = 1;
    scanf("%d", &t);
    for (int k = 1; k <= t; ++k) {
        int n; scanf("%d", &n);

        int a[n+1][n+1];

        int left = 0, right = n-1, top = 0, bot = n-1;
        int val = n*n;
        while (val >= 1) {
            //Trai qua phai
            for (int i = left; i <= right && val <= n*n; ++i) {
                a[top][i] = val--;
            }
            top++;

            //Tren xuong duoi
            for (int i = top; i <= bot && val <= n*n; ++i) {
                a[i][right] = val--;
            }
            right--;

            //Phai qua trai
            for (int i = right; i >= left && val <= n*n; i--) {
                a[bot][i] = val--;
            }
            bot--;
            //Duoi len tren
            for (int i = bot; i >= top && val <= n*n; i--) {
                a[i][left] = val--;
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
