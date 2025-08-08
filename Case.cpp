#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char s[105];
    int n;

    scanf("%s", s);
    n = atoi(s);
    char buf[105];
    sprintf(buf, "%s", s);
    printf("%s", buf);
    printf("%d", n);

    return 0;
}
