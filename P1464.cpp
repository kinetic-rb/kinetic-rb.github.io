#include <iostream>
#include <cstring>

using namespace std;

long f[25][25][25];

inline long w(long a, long b, long c) {
    if (a < 1 || b < 1 || c < 1) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    if (f[a][b][c] != -1) {
        return f[a][b][c];
    }
    if (a < b && b < c) {
        return f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    return f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    memset(f, -1, sizeof f);
    for (long a, b, c; cin >> a >> b >> c && (a != -1 || b != -1 || c != -1); printf("w(%ld, %ld, %ld) = %ld
", a, b, c, w(a, b, c)));
    return 0;
}