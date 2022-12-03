#include <iostream>
#include <queue>
#include <functional>

using namespace std;

struct AC {
    int x, y;
    bool f;
    AC(int x, int y, bool f) {
        this->x = x;
        this->y = y;
        this->f = f;
    }
};

const int dr[][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int maze[1001][1001], d[1001][1001][2];

int main() {
    int n, m, sx, sy, MIN = 0x7fffffff;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 2) {
                sx = i, sy = j;
            }
            d[i][j][0] = d[i][j][1] = 0x7fffffff;
        }
    }
    queue<AC> q;
    function<void (int, int, bool, int)> record = [&](int x, int y, bool f, int step) {
        if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == 1 || (maze[x][y] == 3 && !f) || d[x][y][f] != 0x7fffffff) {
            return ;
        }
        q.push(AC(x, y, f));
        d[x][y][f] = step;
    };
    function<void (int, int)> bfs = [&](int x, int y) -> void {
        for (record(x, y, false, 0); !q.empty();) {
            auto u = q.front();
            q.pop();
            for (auto i : dr) {
                record(u.x + i[0], u.y + i[1], u.f || maze[u.x][u.y] == 4, d[u.x][u.y][u.f] + 1);
            }
        }
    };
    bfs(sx, sy);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 3)
                MIN = min(MIN, d[i][j][1]);
        }
    }
    cout << MIN;
    return 0;
}