#include <iostream>
#include <cstring>
#define short unsigned short
#define register

using namespace std;

int dr[][2] = {-2, -1, -2, 1, -1, -2, -1, 2, 1, -2, 1, 2, 2, -1, 2, 1}, d[405][405];
short n, m, x, y;

inline void dfs(short xx, short yy, short z) {
    if (z > 150)
        return;
    register int zz = z + 1;
    if (xx < 1 || yy < 1 || xx > n || yy > m || zz > d[xx][yy]) {
        return;
    }
    d[xx][yy] = z;
    for (auto i : dr) {
        dfs(xx + i[0], yy + i[1], zz);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> x >> y;
    memset(d, 0x73f3f3e, sizeof d);
    dfs(x, y, 0);
    for (short i = 1; i <= n; i++) {
        for (short j = 1; j <= m; j++) {
            printf("%-5d", (d[i][j] == d[403][403] ? -1 : d[i][j]));
        }
        printf("\n");
    }
    return 0;
}