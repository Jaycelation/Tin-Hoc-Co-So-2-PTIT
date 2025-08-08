#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int check(char s[]) {
    int l = 0, r = strlen(s) - 1;

    while (l < r) {
        if (s[l] != s[r]) {
            return 0;
        }
        ++l; r--;
    }   
    return 1;
}

void sw(char s[]) {
    for (int i = 0; i < strlen(s); ++i) {
        char c = toupper(s[i]);
        if (c == 'A' || c == 'B' || c == 'C') {
            s[i] = 'A';
        } else if (c == 'D' || c == 'E' || c == 'F') {
            s[i] = 'D';
        } else if (c == 'G' || c == 'H' || c == 'I') {
            s[i] = 'G';
        } else if (c == 'J' || c == 'K' || c == 'L') {
            s[i] = 'J';
        } else if (c == 'M' || c == 'N' || c == 'O') {
            s[i] = 'M';
        } else if (c == 'P' || c == 'Q' || c == 'R' || c == 'S') {
            s[i] = 'P';
        } else if (c == 'T' || c == 'U' || c == 'V') {
            s[i] = 'T';
        } else {
            s[i] = 'W';
        }
    }
}

int main() {
    int t; scanf("%d", &t);
    
    while (t--) {
        char s[100];
        scanf("%s", s);
        sw(s);
        // printf("%s\n", s);
        printf(check(s) ? "YES\n" : "NO\n");
    }

    return 0;
}