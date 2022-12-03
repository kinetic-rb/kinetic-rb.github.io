#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

bool vis[101][101];
int b[101][101], dr[][2] = { 0, 1, 0, -1, 1, 0, -1, 0 }, dist[101][101];
int n, MIN = 0x7fffffff;

inline void dfs(int x, int y, int coin, bool f) {
\tif (x + 1 == n and y + 1 == n) {
\t\tMIN = min(MIN, coin);
\t\treturn;
\t}
\tfor (auto& i : dr) {
\t\tint dx = x + i[0], dy = y + i[1];
\t\tif (min(dx, dy) > -1 and max(dx, dy) < n and not vis[dx][dy]) {
\t\t\tif (not b[dx][dy]) {
\t\t\t\tif (f and coin + 2 < dist[dx][dy]) {
\t\t\t\t\tvis[dx][dy] = b[dx][dy] = b[x][y];
\t\t\t\t\tdfs(dx, dy, dist[dx][dy] = coin + 2, false);
\t\t\t\t\tvis[dx][dy] = b[dx][dy] = 0;
\t\t\t\t} else
\t\t\t\t\tcontinue;
\t\t\t} else if (coin + (b[dx][dy] != b[x][y]) < dist[dx][dy]) {
\t\t\t\tvis[dx][dy] = true;
\t\t\t\tdfs(dx, dy, dist[dx][dy] = coin + (b[dx][dy] != b[x][y]), true);
\t\t\t\tvis[dx][dy] = false;
\t\t\t}
\t\t}
\t}
}

int main() {
\tmemset(dist, 127, sizeof dist);
\tint m;
\tcin >> n >> m;
\tfor (int i = 0; i < m; i++) {
\t\tint x, y;
\t\tcin >> x >> y;
\t\tcin >> b[x - 1][y - 1];
\t\tb[x - 1][y - 1]++;
\t}
\tdfs(0, 0, 0, true);
\tcout << (MIN == 0x7fffffff ? -1 : MIN);
\treturn 0;
}