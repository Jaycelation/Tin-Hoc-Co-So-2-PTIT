#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

struct People {
    char name[50];
    int x, y, z;
};

int cmp(const void *a, const void *b) {
    struct People x = *(struct People *)a;
    struct People y = *(struct People *)b;

    int i1 = x.x, j1 = x.y, k1 = x.z;
    int i2 = y.x, j2 = y.y, k2 = y.z;
    if (k2 == k1) {
        if (j2 == j1) {
            return i2 - i1;
        }
        return j2 - j1;
    }
    return k2 - k1;
}

int main() {
    int n; scanf("%d", &n);
    struct People p[50];

    for (int i = 0; i < n; ++i) {
        scanf("%s %d/%d/%d", p[i].name, &p[i].x, &p[i].y, &p[i].z);
    }

    qsort(p, n, sizeof(struct People), cmp);

    printf("%s\n%s", p[0].name, p[n-1].name);

    return 0;
}