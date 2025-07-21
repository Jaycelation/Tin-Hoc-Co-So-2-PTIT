#include <stdio.h>
#include <string.h>


int checkSD1(char s[]) { 
    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return 0;
        }
        int a = s[l]-'0', b = s[r]-'0';
        if (a % 2 != 0 || b % 2 != 0) {
            return 0;
        }
        l++; r--;
    }
    return 1;
}

int checkSD2(char s[]) { 
    int l = 0, r = strlen(s) - 1;

    if (s[0] != '8' || s[strlen(s) - 1] != '8') {
        return 0;
    }

    int total = 0;
    for (int i = 0; i < strlen(s); ++i) {
        total += (s[i]-'0');
    }

    while (l < r) {
        if (s[l] != s[r]) {
            return 0;
        }
        l++; r--;
    }
    return total % 10 == 0;
}

int checkSD3(char s[]) { 
    int l = 0, r = strlen(s) - 1;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] != '2' && s[i] != '3' && s[i] != '5' && s[i] != '7') {
            return 0;
        }
    }

    while (l < r) {
        if (s[l] != s[r]) {
            return 0;
        }

        l++; r--;
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char s[505];
        scanf("%s", s);
        //printf(checkSD1(s) ? "YES\n" : "NO\n");
        //printf(checkSD2(s) ? "YES\n" : "NO\n");
        printf(checkSD3(s) ? "YES\n" : "NO\n");

    }

    return 0;
}