#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char c[505];
        scanf("%s", c);

        int res = 0;
        int val = 0;

        for (int i = 0; i < strlen(c); ++i) {
            if (isdigit(c[i])) {
                val = val * 10 + (c[i] - '0');
            } else {
                if (val > res) {
                    res = val;
                }
                val = 0;
            }
        }
        if (val > res) {
            res = val;
        }

        printf("%d\n", res);
    }

    return 0;
}
