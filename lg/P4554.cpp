#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

struct AC {
    int x, y;
    AC() {}
    AC(int _x, int _y) : x(_x){
        y = _y;
    }
};

deque<AC> Q;
bool mz[1001][1001];
int d[1001][1001], dr[][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int n, m;

inline void record(int x, int y, int step) {
    if (d[x][y] <= step || min(x, y) < 0 || x >= n || y >= m)
        return;
    d[x][y] = step;
    Q.emplace_back(x, y);
}

inline void bfs(int x, int y) {
    for (record(x, y, 0); !Q.empty(); ) {
        auto u = Q.front();
        Q.pop_front();
        for (auto i : dr) {
            int dx = u.x + i[0], dy = i[1] + u.y;
            record(dx, dy, d[u.x][u.y] + (mz[u.x][u.y] ^ mz[dx][dy]));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int sx, sy, ex, ey;
    while (cin >> n >> m && n && m) {
        memset(d, 127, sizeof d);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                mz[i][j] = (ch == '#');
            }
        cin >> sx >> sy >> ex >> ey;
        bfs(sx, sy);
        cout << d[ex][ey] << "\n";
    }
    return 0;
}