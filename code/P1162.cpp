#include <iostream>
#include <queue>

using namespace std;

struct place {
    int x, y;
} Place;

int map1[32][32], visited[32][32], dr[][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
int n;

queue<place> q;

inline void bfs(int x, int y) {
    visited[x][y] = true;
    for (q.push({ x, y }); !q.empty();) {
        auto u = q.front();
        q.pop();
        for (auto i : dr) {
            int dx = u.x + i[0], dy = i[1] + u.y;
            if (dx < 0 || dx > n + 1 || dy < 0 || dy > n + 1 || visited[dx][dy])
                continue;
            visited[dx][dy] = true;
            q.push({dx, dy});
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map1[i][j];
            visited[i][j] = map1[i][j];
        }
    }
    bfs(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] ? cout << map1[i][j] << ' ' : cout << "2 ";
        }
        cout << '\n';
    }
    return 0;
}