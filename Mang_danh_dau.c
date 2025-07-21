#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int feq[105] = {0};


int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    if (feq[x] != feq[y]) {
        return feq[y] - feq[x];
    }

    return x - y;
}

int main() {
    int arr[10] = {1, 2, 3, 1, 1, 2, 4, 5, 2, 5};

    for (int i = 0; i < 10; ++i) {
        feq[arr[i]]++;
        printf("%d ", arr[i]);
    }

    printf("\n");

    qsort(arr, 10, sizeof(int), cmp);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}