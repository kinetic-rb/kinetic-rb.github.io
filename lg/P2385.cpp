#include <iostream>
#include <queue>
#include <cstring>
#include <functional>

using namespace std;

int mz[40][40], dist[40][40];

struct AC {
\tint x, y;
\tAC() {}
\tAC(int x, int y) : x(x) {
\t\tthis->y = y;
\t}
};

int main() {
\tmemset(dist, 127, sizeof dist);
\tint n, m, c, d, sx, sy, ex, ey;
\tcin >> n >> m >> c >> d;
\tfor (int i = 0; i < n; i++)
\t\tfor (int j = 0; j < m; j++) {
\t\t\tcin >> mz[i][j];
\t\t\tif (mz[i][j] == 2)
\t\t\t\tmz[i][j] = 0;
\t\t\tif (mz[i][j] == 3) {
\t\t\t\tsx = i;
\t\t\t\tsy = j;
\t\t\t}
\t\t\tif (mz[i][j] == 4) {
\t\t\t\tex = i;
\t\t\t\tey = j;
\t\t\t}
\t\t}
\tconst int dr[][2] = {c, d, -c, d, c, -d, -c, -d, d, c, -d, c, d, -c, -d, -c};
\tqueue<AC> Q;
\tfunction<void(int, int, int)> record = [&](int x, int y, int step) {
\t\tif (min(x, y) > -1 && x < n && y < m && mz[x][y] && step < dist[x][y]) {
\t\t\tQ.push(AC(x, y));
\t\t\tdist[x][y] = step;
\t\t}
\t};
\tfunction<void(int, int)> bfs = [&](int x, int y) {
\t\tfor (record(x, y, 0); !Q.empty();) {
\t\t\tauto u = Q.front();
\t\t\tQ.pop();
\t\t\tfor (auto i : dr) {
\t\t\t\tint dx = i[0] + u.x, dy = u.y + i[1];
\t\t\t\trecord(dx, dy, dist[u.x][u.y] + 1);
\t\t\t}
\t\t}
\t};
\tbfs(sx, sy);
\tcout << dist[ex][ey];
\treturn 0;
}