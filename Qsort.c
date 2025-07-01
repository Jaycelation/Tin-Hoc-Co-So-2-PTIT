#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct SinhVien {
    int maSV;
    char tenSV[100];
    float diem;
};

void addSV(struct SinhVien *sv, int ma, char *ten, float diem) {
    sv->maSV = ma;
    strcpy(sv->tenSV, ten);
    sv->diem = diem;
}

int cmp(const void *a, const void *b) {
    struct SinhVien *sv1 = (struct SinhVien*) a;
    struct SinhVien *sv2 = (struct SinhVien*) b;

    if (sv1->diem < sv2->diem) {
        return -1;
    }
    else if (sv1->diem > sv2->diem) {
        return 1;
    }
    return sv1->maSV - sv2->maSV;
}

int main() {
    struct SinhVien sv[100];

    addSV(&sv[0], 6, "Nguyen Van A", 8.5);
    addSV(&sv[1], 2, "Tran Thi B", 9.0);
    addSV(&sv[2], 3, "Le Van C", 7.0);
    addSV(&sv[3], 4, "Pham Thi D", 8.0);
    addSV(&sv[4], 5, "Hoang Van E", 8.5);

    qsort(sv, 5, sizeof(struct SinhVien), cmp);

    for (int i = 0; i < 5; ++i) {
        printf("%d %s %.1f\n", sv[i].maSV, sv[i].tenSV, sv[i].diem);
    }

    return 0;
}