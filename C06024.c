#include <stdio.h>
#include <string.h>
#include <ctype.h>

void add(char *a, char *b, char *result) {
    char tmp[505];
    
    int carry = 0, k = 0;

    int la = strlen(a), lb = strlen(b);

    int i = la - 1, j = lb - 1;
    while (i >= 0 || j >= 0 || carry) {
        int dga = (i >= 0) ? a[i--] - '0' : 0;
        int dgb = (j >= 0) ? b[j--] - '0' : 0;

        int sum = dga + dgb + carry;
        carry = sum / 10;
        tmp[k++] = (sum % 10) + '0';
    }

    for (int i = 0; i < k; ++i) {
        result[i] = tmp[k-i-1];
    }
    result[k] = '\0';
}

void minus(char *a, char *b, char *result) {
    char tmp[505];

    int borrow = 0, k = 0;

    int la = strlen(a), lb = strlen(b);
    int i = la - 1, j = lb - 1;

      while (i >= 0) {
        int dga = a[i--] - '0';
        int dgb = (j >= 0) ? b[j--] - '0' : 0;

        int sub = dga - dgb - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        tmp[k++] = sub + '0';
    }
    while (k > 1 && tmp[k - 1] == '0') {
        k--;
    }
    for (int i = 0; i < k; ++i) {
        result[i] = tmp[k - i - 1];
    }
    result[k] = '\0';
}

int main() {
    int t;

    scanf("%d", &t);
    getchar();

    for (int i = 0; i < t; ++i) {
        char a[505], b[505], result[505];

        fgets(a, sizeof(a), stdin);
        a[strcspn(a, "\n")] = 0;

        fgets(b, sizeof(b), stdin);
        b[strcspn(b, "\n")] = 0;

        add(a, b, result);
        printf("%s\n", result);
    }

    return 0;
}