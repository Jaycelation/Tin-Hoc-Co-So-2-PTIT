#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int t;
    scanf("%d", &t);
    getchar();

    int roman[256] = {0};
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    for (int i = 0; i < t; ++i) {
        char s[205];
        fgets(s, sizeof(s), stdin);
        int total = 0;
        for (int j = 0; j < strlen(s); ++j) {
            int val = roman[s[j]];
            int next_val = roman[s[j+1]];
            if (val < next_val) {
                total += next_val - val;
                j++;
            }
            else {
                total += val;
            }

        }
        printf("%d\n", total);
    }

    return 0;
}