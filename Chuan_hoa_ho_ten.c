#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    getchar();

    while (t--) {
        char name[30];
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        char *token = strtok(name, " ");
        while (token != NULL) {
            token[0] = toupper(token[0]);
            for (int i = 1; i < strlen(token); ++i) {
                token[i] = tolower(token[i]);
            }
            printf("%s", token);
            token = strtok(NULL, " ");
            if (token != NULL) {
                printf(" ");
            }
        }
    }

    return 0;
}