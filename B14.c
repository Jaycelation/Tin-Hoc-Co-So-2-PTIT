#include <stdio.h>

#define MAX 100

int main() {
    int n, a[MAX][MAX];
    scanf("%d", &n);

    // Nhập ma trận
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);

    // Lưu giá trị viền ngoài cùng vào mảng tạm (theo chiều kim đồng hồ)
    int temp[4 * MAX];
    int idx = 0;

    // Trên
    for (int j = 0; j < n; ++j)
        temp[idx++] = a[0][j];
    // Phải
    for (int i = 1; i < n; ++i)
        temp[idx++] = a[i][n - 1];
    // Dưới
    for (int j = n - 2; j >= 0; --j)
        temp[idx++] = a[n - 1][j];
    // Trái
    for (int i = n - 2; i >= 1; --i)
        temp[idx++] = a[i][0];

    // Dịch vòng sang phải 1 đơn vị
    int last = temp[idx - 1];
    for (int i = idx - 1; i > 0; --i)
        temp[i] = temp[i - 1];
    temp[0] = last;

    idx = 0;
    // Trên
    for (int j = 0; j < n; ++j)
        a[0][j] = temp[idx++];
    // Phải
    for (int i = 1; i < n; ++i)
        a[i][n - 1] = temp[idx++];
    // Dưới
    for (int j = n - 2; j >= 0; --j)
        a[n - 1][j] = temp[idx++];
    // Trái
    for (int i = n - 2; i >= 1; --i)
        a[i][0] = temp[idx++];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}
