#include <stdio.h>

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 100; i < 1000; i++) {
        if (i % 10 + i / 10 % 10 + i / 100 == n)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}