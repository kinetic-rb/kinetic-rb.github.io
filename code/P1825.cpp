#include <iostream>
#include <deque>
#define int short

using namespace std;

struct WA {
    int x, y, step;
    WA() {}
    WA(int x, int y, int step) : x(x) {
        this->y = y;
        this->step = step;
    }
};

deque<WA> Q;

char mz[305][305];
bool vis[305][305];
const int dr[][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
int n, m;

inline void findloc(int& nx, int& ny) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mz[i][j] == mz[nx][ny] && (i != nx || j != ny)) {
                nx = i;
                ny = j;
                return;
            }
}

signed main() {
    ios_base::sync_with_stdio(false);
    int sx, sy;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> mz[i][j];
            if (mz[i][j] == '@') {
                sx = i;
                sy = j;
            }
        }
    for (Q.emplace_back(sx, sy, 0); !Q.empty(); Q.pop_front()) {
        if (mz[Q.front().x][Q.front().y] == '=') {
            cout << Q.front().step;
            return 0;
        }
        if (mz[Q.front().x][Q.front().y] >= 'A' && mz[Q.front().x][Q.front().y] <= 'Z')
            findloc(Q.front().x, Q.front().y);
        for (auto i : dr) {
            int dx = Q.front().x + i[0], dy = Q.front().y + i[1];
            if (dx > -1 && dx < n && dy > -1 && dy < m && mz[dx][dy] != '#' && !vis[dx][dy]) {
                vis[dx][dy] = true;
                Q.emplace_back(dx, dy, Q.front().step + 1);
            }
        }
    }
    return 0;
}