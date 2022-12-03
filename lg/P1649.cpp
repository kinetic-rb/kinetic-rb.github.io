#include <iostream>

using namespace std;

int n, m, MIN = 0x7fffffff, ex, ey;
signed dr[][2] = { 1, 0, 0, -1, -1, 0, 0, 1 };
bool b[101][101];

inline void dfs(int x, int y, int step, int w) {
    if (step >= MIN)
        return;
    if (x == ex && y == ey) {
        MIN = min(MIN, step);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int dx = x + dr[i][0], dy = dr[i][1] + y;
        if (min(dx, dy) > -1 && max(dx, dy) < n && b[dx][dy]) {
            b[dx][dy] = false;
            dfs(dx, dy, step + (w != i), i);
            b[dx][dy] = true;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    int sx, sy;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            if (x == 'A') {
                sx = i;
                sy = j;
            }
            if (x == 'B') {
                ex = i;
                ey = j;
            }
            b[i][j] = (x != 'x');
        }
    for (int i = 0; i < 4; i++)
        dfs(sx, sy, 0, i);
    cout << (MIN == 0x7fffffff ? -1 : MIN);
    return 0;
}