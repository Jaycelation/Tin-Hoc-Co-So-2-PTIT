#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

bool prime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

char *toLower(char *s) {
    for (int i = 0; i < strlen(s); ++i) {
        s[i] = tolower(s[i]);
    }
    return s;
}

char *toUpper(char *s) {
    for (int i = 0; i < strlen(s); ++i) {
        s[i] = toupper(s[i]);
    }
    return s;
}

long long fibonacci[94];

void fibo() {
    fibonacci[0] = fibonacci[1] = 1;
    for (int i = 2; i < 94; ++i) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
}

struct WordCount {
    int count;
    char word[105];
};

long long reverse(long long n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

void toh(int n, char s, char t, char tg) {
    if (n == 1) {
        printf("%c -> %c\n", s, tg);
        return;
    }
    toh(n - 1, s, tg, t);
    printf("%c -> %c\n", s, tg);
    toh(n - 1, t, s, tg);
}

long long countWays(long long n) {
    long long cnt = 0;
    for (int m = 1; m * (m-1) / 2 < n; ++m) {
        int num = n - m * (m-1)/2;
        if (num % m == 0) {
            cnt++;
        }
    }
    return cnt;
}

int isIncr(char *s, int st, int en) {
    for (int i = st; i < en; ++i) {
        if (s[i] >= s[i+1]) {
            return 0;
        }
    }
    return 1;
}

int isDecr(char *s, int st, int en) {
    for (int i = st; i < en; ++i) {
        if (s[i] <= s[i+1]) {
            return 0;
        }
    }
    return 1;
}

int check(char *s) {
    int len = strlen(s);
        if (len < 3) {
            return 0;
        }
        for (int i = 1; i < len - 1; ++i) {
            if (isIncr(s, 0, i) && isDecr(s, i, len - 1)) {
                return 1;
            }
        }
    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

int exists(int a[], int size, int x) {
    for (int i = 0; i < size; ++i) {
        if (a[i] == x) {
            return 1;
        }
    }
    return 0;
}

int sum(long long n) {
    int rs = 0;
    while (n) {
        rs += n % 10;
        n /= 10;
    }
    return rs;
}

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    int sx = sum(x);
    int sy = sum(y);
    if (sx != sy) {
        return sx - sy;
    } else {
        return x - y;
    }
}

int max3(int a, int b, int c){
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int cmp2(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void sortCol(int a[105][105], int n, int col) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][col] > a[j][col]) {
                swap(&a[i][col], &a[j][col]);
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    fibo();
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int i = a-1; i < b; ++i) {
            printf("%lld ", fibonacci[i]);
        }
        printf("\n");
    }
    return 0;
}
