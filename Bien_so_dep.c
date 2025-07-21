#include <stdio.h>
#include <string.h>

int BSD1(char s[]) {
    int len = strlen(s);
    int j = 0;
    for (int i = 1; i < len-1; ++i) {
        if (s[i] == '.') {
            continue;
        }
        if (s[j] == '.') {
            continue;
        }
        int x = s[i] - '0';
        int y = s[j] - '0';
        if (x <= y) {
            return 0;
        }
        j++;
    }
    return 1;
}

int BSD2(char s[]) {
    int len = strlen(s);
    int y = s[0]-'0';
    for (int i = 1; i < len; ++i) {
        if (s[i] == '.') {
            continue;
        }
        int x = s[i] - '0';
        if (x != y) {
            return 0;
        }
    }
    return 1;
}

int BSD3(char s[]) {
    int len = strlen(s);

    int x = s[0]-'0', y = s[4]-'0';

    for (int i = 0; i < 3; ++i) {
        int val = s[i] - '0';
        if (x != val) {
            return 0;
        }
    }

    for (int i = 4; i < len; ++i) {
        int val = s[i] - '0';
        if (y != val) {
            return 0;
        }
    }
    return 1;
}

int BSD4(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] == '.') {
            continue;
        }
        int val = s[i] - '0';
        if (val != 6 && val != 8) {
            return 0;
        }
    }
    return 1;
}

int checkBSD(char s[]) {
    int flag = 0;

    if (BSD1(s) || BSD2(s) || BSD3(s) || BSD4(s)) {
        flag = 1;
    }

    //printf("Debug: %d %d %d %d\n", BSD1(s), BSD2(s), BSD3(s), BSD4(s));

    return flag;
}

int main() {
    int t; scanf("%d", &t);

    while (t--) {
        char a[100], b[100];

        scanf("%s %s", a, b);
        printf(checkBSD(b) ? "YES\n" : "NO\n");

    }

    return 0;
}