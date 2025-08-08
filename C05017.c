#include <stdio.h>

int main() {

    int t; scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int a[n+1][m+1];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }

        int left = 0, right = m-1, top = 0, bot = n-1;
        int val = 1;

        while(val <= n*m) {
            //Trai qua phai
            for (int i = left; i <= right && val <= n*m; ++i) {
                printf("%d ", a[top][i]);
                val++;
            }
            top++;
            //Tren xuong duoi
            for (int i = top; i <= bot && val <= n*m; ++i) {
                printf("%d ", a[i][right]);
                val++;
            }
            right--;
            //Phai qua trai
            for (int i = right; i >= left && val <= n*m; i--) {
                printf("%d ", a[bot][i]);
                val++;
            }   
            bot--;
            //Duoi len tren
            for (int i = bot; i >= top && val <= n*m; i--) {
                printf("%d ", a[i][left]);
                val++;
            }
            left++;
        }

        printf("\n");
    }

    return 0;
}
