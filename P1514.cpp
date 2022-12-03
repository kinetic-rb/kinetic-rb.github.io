#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int l[505][505], r[505][505], h[505][505], dr[][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
bool vis[505][505];

inline void dfs(int x, int y) {
    vis[x][y] = 1;
    for (auto& i : dr) {
        int dx = x + i[0], dy = y + i[1];
        if (dx < 1 || dx > n || dy < 1 || dy > m || h[dx][dy] >= h[x][y])
            continue;
        if (!vis[dx][dy])
            dfs(dx, dy);
        l[x][y] = min(l[x][y], l[dx][dy]);
        r[x][y] = max(r[x][y], r[dx][dy]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int cnt = 0;
    cin >> n >> m;
    memset(l, 127, sizeof l);
    for (int i = 1; i <= m; i++)
        l[n][i] = r[n][i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[i][j];
    for (int i = 1; i <= m; i++)
        if (!vis[1][i])
            dfs(1, i);
    for (int i = 1; i <= m; i++)
        if (!vis[n][i])
            cnt++;
    if (cnt) {
        printf("0
%d", cnt);
        return 0;
    }
    for (int le = 1; le <= m; cnt++) {
        int MAX = 0;
        for (int i = 1; i <= m; i++)
            if (le >= l[1][i])
                MAX = max(MAX, r[1][i]);
        le = ++MAX;
    }
    printf("1
%d", cnt);
    return 0;
}