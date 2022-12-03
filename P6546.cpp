#include <stdio.h>

inline int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int n, a, b, now = 0, day = 1;
    scanf("%d%d%d", &a, &b, &n);
    day += max(0, (n - a - 1) / (a - b));
    for (n -= (day - 1) * (a - b); ; day++) {
        now += a;
        if (now >= n) {
            printf("%d", day);
            return 0;
        }
        now -= b;
    }
    return 0;
}