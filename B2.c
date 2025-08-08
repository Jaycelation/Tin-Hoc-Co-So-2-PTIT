#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n,b; scanf("%d %d", &n, &b);

        char c[1005];
        int i = 0;
        while (n > 0) {
            if (b < 10) {
                c[i] = n % b + '0';
            }
            else {
                c[i] = n % b - 10 + 'A';
            }
            n /= b;
            i++;
        }
        for (int j = i - 1; j >= 0; j--) {
            printf("%c", c[j]);
        }
        printf("\n");
    }

    return 0;
}