#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char s[205];

    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    int count1 = 0, count2 = 0, count3 = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (isdigit(s[i])) {
            count1++;
        } else if (isalpha(s[i])) {
            count2++;
        } else {
            count3++;
        }
    }

    printf("%d %d %d\n", count2, count1, count3);
    return 0;
}