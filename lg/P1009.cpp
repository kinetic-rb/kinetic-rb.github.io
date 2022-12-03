#include <iostream>
#include <cstring>

using namespace std;

int a[100000], n, y, xy[100000], s[100000];

inline void add() {
    memset(xy, 0, sizeof(xy));
    xy[0] = max(s[0], a[0]);
    for (register int i = 1; i <= xy[0]; xy[i++] %= 10) {
        xy[i] += s[i] + a[i];
        xy[i + 1] = xy[i] / 10;
    }
    for (; xy[xy[0] + 1] > 0; xy[++xy[0]] %= 10) {
        xy[xy[0] + 2] = xy[xy[0] + 1] / 10;
    }
    s[0] = xy[0];
    for (register int i = 1; i <= xy[0]; i++)
        s[i] = xy[i];
}

int main() {
    scanf("%d", &n);
    a[0] = a[1] = s[0] = 1;
    for (y = 1; y <= n; y++) {
        memset(xy, 0, sizeof(xy));
        xy[0] = a[0];
        for (register int i = 1; i <= a[0]; i++) {
            xy[i] += a[i] * y;
            xy[i + 1] = xy[i] / 10;
            xy[i] %= 10;
        }
        while (xy[xy[0] + 1] > 0) {
            xy[xy[0] + 2] = xy[xy[0] + 1] / 10;
            xy[xy[0] + 1] %= 10;
            xy[0]++;
        }
        for (register int i = 1; i <= xy[0]; i++)
            a[i] = xy[i];
        a[0] = xy[0];
        add();
    }
    for (register int i = s[0]; i > 0; i--)
        printf("%d", s[i]);
    exit(0);
}