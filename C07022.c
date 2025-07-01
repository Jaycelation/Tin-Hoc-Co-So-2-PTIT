#include <stdio.h>
#include <string.h>

struct SinhVien {
    int maSV;
    char tenSV[100];
    float diem1, diem2, diem3;
};

void addSV(struct SinhVien *sv, int ma, char *ten, float d1, float d2, float d3) {
    sv->maSV = ma;
    strcpy(sv->tenSV, ten);
    sv->diem1 = d1;
    sv->diem2 = d2;
    sv->diem3 = d3;
}

int diemTangDan(struct SinhVien *sv) {
    return (sv->diem1 < sv->diem2 && sv->diem2 < sv->diem3);
}

void printSV(struct SinhVien sv[], int n) {
    for (int i = 0; i < n; ++i) {
        if (diemTangDan(&sv[i])) {
            printf("%d %s %.1f %.1f %.1f\n", sv[i].maSV, sv[i].tenSV, sv[i].diem1, sv[i].diem2, sv[i].diem3);
        }
    }
}

int main() {
    struct SinhVien sv[100];
    int count = 0;

    while (1) {
        int choice;
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            int n;
            scanf("%d", &n);
            getchar();

            for (int i = 0; i < n; ++i) {
                char ten[100];
                float d1, d2, d3;

                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = 0;

                scanf("%f %f %f", &d1, &d2, &d3);
                getchar();

                addSV(&sv[count], count + 1, ten, d1, d2, d3);
                count++;
            }

            printf("%d\n", n);

        } else if (choice == 2) {
            int id;
            scanf("%d", &id);
            getchar();

            for (int i = 0; i < count; ++i) {
                if (sv[i].maSV == id) {
                    char ten[100];
                    float d1, d2, d3;

                    fgets(ten, sizeof(ten), stdin);
                    ten[strcspn(ten, "\n")] = 0;

                    scanf("%f %f %f", &d1, &d2, &d3);
                    getchar();

                    addSV(&sv[i], id, ten, d1, d2, d3);
                    break;
                }
            }

            printf("%d\n", id);

        } else if (choice == 3) {
            printSV(sv, count);
            break;
        }
    }

    return 0;
}