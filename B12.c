#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

struct MatHang {
    int maMH;
    char tenMH[50], nhomMH[50];
    float giaMua, giaBan;
};

int cmp(const void *a, const void *b) {
    struct MatHang x = *(struct MatHang *)a;
    struct MatHang y = *(struct MatHang *)b;
    float xP = x.giaBan - x.giaMua, yP = y.giaBan - y.giaMua;
    return yP - xP;
}

int main() {
    int n; scanf("%d", &n);
    getchar();
    struct MatHang mh[50];
    int count = 1;

    for (int i = 0; i < n; ++i) {
        fgets(mh[i].tenMH, sizeof(mh[i].tenMH), stdin);
        mh[i].tenMH[strcspn(mh[i].tenMH, "\n")] = 0;

        fgets(mh[i].nhomMH, sizeof(mh[i].nhomMH), stdin);
        mh[i].nhomMH[strcspn(mh[i].nhomMH, "\n")] = 0;

        scanf("%f %f", &mh[i].giaMua, &mh[i].giaBan);
        getchar();

        mh[i].maMH = i + 1;
    }

    qsort(mh, n, sizeof(struct MatHang), cmp);

    for (int i = 0; i < n; ++i) {
        printf("%d %s %s %.2f\n", mh[i].maMH, mh[i].tenMH, mh[i].nhomMH, mh[i].giaBan - mh[i].giaMua);
    }

    return 0;
}