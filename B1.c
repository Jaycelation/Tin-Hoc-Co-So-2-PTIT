#include <stdio.h>
#include <string.h>

int main() {

    int count[26] = {0};

    char c[1005];
    scanf("%s", c);

    for (int i = 0; i < strlen(c); ++i) {
        count[c[i] - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        if (count[i]) {
            res++;
        }
    }
    printf("%d\n", res);
    return 0;
}