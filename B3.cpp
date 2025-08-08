#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char c[205];

    scanf("%s", c);

    int x = strlen(c) % 3;
    int i = 0, n = strlen(c);

    if (x == 1) {
        int val = c[0] - '0';
        printf("%d", val);
        i = 1;
    } else if (x == 2) {
        int val = (c[0] - '0') * 10 + (c[1] - '0');
        printf("%d", val);
        i = 2;
    }

    for (int j = i; j < n; j += 3) {
        int val = (c[j] - '0') * 100 + (c[j+1]-'0')*10 + c[j+2]-'0';
        printf("%d", val);
    }
    
    return 0;
}