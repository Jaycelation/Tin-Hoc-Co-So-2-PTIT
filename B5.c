#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char P[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int find(char c) {
    for (int i = 0; i < strlen(P); ++i) {
        if (P[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    int k;
    char c[105];

    char r[105];
    while (1) {
        scanf("%d", &k);
        if (k == 0) {
            break;
        }
        scanf("%s", c);
        for (int i = 0; i < strlen(c); ++i) {
            int j = find(c[i]);

            r[i] = P[(j + k) % 28];
        }
        r[strlen(c)] = '\0';
        for (int i = strlen(c) - 1; i >= 0; i--) {
            printf("%c", r[i]);
        }
        printf("\n");
    }

    return 0;
}