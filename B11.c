#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct People {
    char id[105], ten[105], donvi[105];
    double vantoc;
};

void cID(const char *src, char *dest) {
    char temp[205];
    strncpy(temp, src, sizeof(temp));

    char *tok = strtok(temp, " ");
    int i = 0;
    while (tok != NULL) {
        sprintf(dest + i, "%c", toupper(tok[0]));
        i++;
        tok = strtok(NULL, " ");
    }
    dest[i] = 0;
}

int cmp(const void* a, const void *b) {
    struct People x = *(struct People *)a;
    struct People y = *(struct People *)b;

    return y.vantoc-x.vantoc;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    struct People p[n];

    for (int i = 0; i < n; ++i) {
        fgets(p[i].ten, sizeof(p[i].ten), stdin);
        p[i].ten[strcspn(p[i].ten, "\n")] = 0;

        fgets(p[i].donvi, sizeof(p[i].donvi), stdin);
        p[i].donvi[strcspn(p[i].donvi, "\n")] = 0;

        char temp1[20], temp2[20];
        cID(p[i].donvi, temp1);
        cID(p[i].ten, temp2);
        sprintf(p[i].id, sizeof(p[i].id), "%s%s", temp1, temp2);

        int h, m;
        scanf("%d:%d", &h, &m);
        getchar();

        double t = (h - 6) + m / 60.0;
        p[i].vantoc = 120.0 / t;
    }

    qsort(p, n, sizeof(struct People), cmp);

    for (int i = 0; i < n; ++i) {
        printf("%s %s %s %.0lf Km/h\n", p[i].id, p[i].ten, p[i].donvi, p[i].vantoc);
    }

    return 0;
}
