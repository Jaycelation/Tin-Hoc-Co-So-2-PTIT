#include <stdio.h>
#include <string.h>

int check(int n)
{
    int x = 0, m = n;
    while (n != 0)
    {
        int k = n % 10;
        x = x * 10 + k;
        n /= 10;
    }
    if (m == x)
        return 1;
    return 0;
}

int toInt(char s[]) {
    int val = 0;
    for (int i = 0; i < strlen(s); ++i) {
        val = val * 10 + (s[i] - '0');
    }
    return val;
}

int main() {

    char n[10];
    int k;

    scanf("%s %d", n, &k);
    char temp[10];
    
    int len = strlen(n) - 1;
    int idx = len - k + 1;
    int cnt = 0;
    //printf("%d %d\n", len, idx);
    for (int i = idx; i <= len; ++i) {
        //printf("%c", n[i]);
        //printf("%d ", i);
        temp[cnt++] = n[i];
    }
    int val = 0;
    for (int i = 0; i < strlen(temp); ++i) {
        //printf("%c", temp[i]);
        val = val * 10 + (temp[i] - '0');
    }
    if (check(val)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}