#include <iostream>
#include <queue>

using namespace std;

struct Cor {
    int x, y, s;
    Cor() {}
    Cor(int xx, int yy, int ss) : x(xx), y(yy), s(ss) {}
};

queue<Cor>q;

int n, m, t, sx, sy, ex, ey;
int dr[][2] = {0, 1, 0, -1, 1, 0, -1, 0}, f[110][110][20];
char s[101][101];

inline void record(const Cor& u, const Cor& th) {
    if (f[th.x][th.y][th.s]) {
        f[th.x][th.y][th.s] += f[u.x][u.y][u.s];
        return;
    }
    if (th.x < 1 || th.x > n || th.y < 1 || th.y > m || s[th.x][th.y - 1] == '*' || th.s > t)
        return;
    f[th.x][th.y][th.s] += f[u.x][u.y][u.s];
    q.push(th);
}

inline void bfs() {
    for (q.push(Cor(sx, sy, 0)); !q.empty(); q.pop())
        for (auto i : dr)
            record(q.front(), Cor(q.front().x + 0[i], q.front().y + 1[i], q.front().s + 1));
}

int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    cin >> sx >> sy >> ex >> ey;
    f[sx][sy][0] = 1;
    bfs();
    cout << f[ex][ey][t];
    return 0;
}