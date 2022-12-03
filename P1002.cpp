#include <stdio.h>

int dir[8][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
int d[30][30];
long long dp[30][30] = {1};

int main() {
    int n, m, cx, cy;
    scanf("%d%d%d%d", &n, &m, &cx, &cy);
    d[cx][cy] = 1;
    for (int i = 0; i < 8; i++) {
        int tx = cx + dir[i][0], ty = cy + dir[i][1];
        if (tx >= 0 && tx <= n && ty >= 0 && ty <= m) {
            d[tx][ty] = 1;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!d[i][j]) {
                if (i) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
    }
    printf("%lld", dp[n][m]);
    return 0;
}