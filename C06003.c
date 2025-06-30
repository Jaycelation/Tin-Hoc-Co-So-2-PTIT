#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    getchar();

    for (int i = 0; i < t; ++i) {
        char s[205];
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = 0;

        int count = 0;
        char *tok = strtok(s, " ");
        while (tok != NULL) {
            count++;
            tok = strtok(NULL, " ");
        }
        printf("%d\n", count);
    }

    return 0;
}
