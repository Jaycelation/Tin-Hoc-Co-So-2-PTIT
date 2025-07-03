#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int day, month, year;
        scanf("%d/%d/%d", &day, &month, &year);
        printf("%02d/%02d/%04d\n", day, month, year);
    }

    return 0;
}
