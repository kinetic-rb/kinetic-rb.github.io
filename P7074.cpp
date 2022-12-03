#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int ac[1001][1001], n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &ac[i][j]);
    long f[n + 1][m + 1];
    f[1][1] = ac[1][1];
    for (int i = 2; i <= n; i++)f[i][1] = f[i - 1][1] + ac[i][1];
    for (int i = 2; i <= m; i++) {
        f[1][i] = f[1][i - 1] + ac[1][i];
        for (int j = 2; j <= n; j++)
            f[j][i] = max(f[j - 1][i], f[j][i - 1]) + ac[j][i];
        long now = f[n][i - 1] + ac[n][i];
        f[n][i] = max(f[n][i], now);
        for (int j = n - 1; j > 0; j--)
            f[j][i] = max(f[j][i], (now = max(now, f[j][i - 1]) + ac[j][i]));
    }
    printf("%lld
", f[n][m]);
    return 0;
}