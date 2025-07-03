#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[100];
    char dob[15];
    float d1, d2, d3;
    int id;
};

int cmp(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;
    int totalA = studentA->d1 + studentA->d2 + studentA->d3;
    int totalB = studentB->d1 + studentB->d2 + studentB->d3;

    //Sap xep giam dan
    if (totalA > totalB) return -1;
    if (totalA < totalB) return 1;

    //Neu tong diem bang nhau, so sanh id
    return studentA->id - studentB->id;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    struct Student students[100];
    float max_score = -1.0;
    for (int i = 0; i < n; ++i) {
        char name[100], dob[15];
        float d1, d2, d3;
        int id = i+1;

        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        //int d, m, y;
        //scanf("%d/%d/%d", &d, &m, &y);
        //sprintf(dob, "%02d/%02d/%04d", d, m, y);

        scanf("%s %f %f %f", dob, &d1, &d2, &d3);
        getchar();
        max_score = (d1 + d2 + d3 > max_score) ? (d1 + d2 + d3) : max_score;
        strcpy(students[i].name, name);
        strcpy(students[i].dob, dob);
        students[i].d1 = d1;
        students[i].d2 = d2;
        students[i].d3 = d3;
        students[i].id = id;
    }

    qsort(students, n, sizeof(struct Student), cmp);

    for (int i = 0; i < n; ++i) {
        if (students[i].d1 + students[i].d2 + students[i].d3 == max_score) {
            printf("%d %s %s %.1f\n", students[i].id, students[i].name, students[i].dob, students[i].d1+students[i].d2+students[i].d3);
        }
    }

    return 0;
}