#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[105];
    scanf("%s", a);
    char st[105];
    int top = -1;
    for (int i = 0; i < strlen(a); ++i) {
        if (top >= 0 && a[i] == a[top]) {
            top--;
        } else {
            top++;
            st[top] = a[i];
        }
    }
    if (top == -1) {
        printf("Empty String\n");
    }
    else {
        st[top+1] = '\0';
        printf("%s\n", st);
    }

    return 0;
}