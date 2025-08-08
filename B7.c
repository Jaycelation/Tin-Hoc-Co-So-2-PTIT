#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp(const void *a, const void *b) {
    char x = *(char*)a;
    char y = *(char*)b;
    return x - y;
}

int main() {
    int t; scanf("%d", &t);
    int cnt = 1;
    while (t--) {
        char s1[1005], s2[1005];
        scanf("%s %s", s1, s2);

        qsort(s1, strlen(s1), sizeof(char), cmp);
        qsort(s2, strlen(s2), sizeof(char), cmp);
        // printf("%s\n%s\n", s1, s2);
        printf("Test %d: ", cnt);
        cnt++;
        if (strcmp(s1, s2) == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}