#include <iostream>

using namespace std;

int mz[101][101], dr[][2] = { 1, 0, -1, 0, 1, 1, 0, 1, -1, 1, 1, -1, 0, -1, -1, -1 };
int n, m;

inline bool NOT_END() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mz[i][j] == '.')
                return true;
    return false;
}

inline void move(int x, int y) {
    if (mz[x][y] == -10000) {
        for (auto i : dr) {
            int dx = x + i[0], dy = i[1] + y;
            if (min(dx, dy) > 0 && dx <= n && dy <= m && mz[dx][dy] != '*' && mz[dx][dy] != -10000)
                mz[dx][dy] = -9999;
        }
    }
}

inline void upd() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (mz[i][j] == -9999)
                mz[i][j] = -10000;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    int zx, zy, cnt = 0;
    cin >> m >> n >> zy >> zx;
    for (int i = n; i > 0; i--)
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            mz[i][j] = c;
        }
    mz[zx][zy] = -10000;
    while (NOT_END()) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                move(i, j);
        upd();
        cnt++;
    }
    cout << cnt;
    return 0;
}