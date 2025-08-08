#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct Time {
    int x, y, z;
    int val;
};

int cmp(const void *a, const void *b) {
    struct Time x = *(struct Time*) a;
    struct Time y = *(struct Time*) b;

    return x.val - y.val;
}

int main() {
    int n; scanf("%d", &n);
    struct Time time[n];
    for (int i = 0; i < n; ++i) {
        int x, y, z; scanf("%d %d %d", &x, &y, &z);
        int val = x * 3600 + y * 60 + z;
        time[i].x = x;
        time[i].y = y;
        time[i].z = z;
        time[i].val = val;
    }

    qsort(time, n, sizeof(struct Time), cmp);

    for (int i = 0; i < n; ++i) {
        printf("%d %d %d\n", time[i].x, time[i].y, time[i].z);
    }

    return 0;
}