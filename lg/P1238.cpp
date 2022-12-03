#include <iostream>

using namespace std;

const int dr[][2] = { 0, -1, -1, 0, 0, 1, 1, 0 };
bool num[16][16];

struct CE {
\tint x, y;
\tCE() {}
\tCE(int x, int y) : x(x), y(y) {}
} rec[2000];

int n, m, ex, ey;
bool flag = true;

inline void dfs(int x, int y, int step) {
\tif (x == ex && y == ey) {
\t\tprintf("(1,1)->");
\t\tfor (int i = 1; i < step; i++)
\t\t\tprintf("(%d,%d)->", rec[i].x, rec[i].y);
\t\tprintf("(%d,%d)
", x, y);
\t\tflag = false;
\t\treturn;
\t}
\tfor (auto& i : dr) {
\t\tint dx = x + i[0], dy = i[1] + y;
\t\tif (min(dx, dy) > 0 && dx <= n && dy <= m && num[dx][dy]) {
\t\t\trec[step + 1] = CE(dx, dy);
\t\t\tnum[dx][dy] = false;
\t\t\tdfs(dx, dy, step + 1);
\t\t\tnum[dx][dy] = true;
\t\t}
\t}
}

int main() {
\tint sx, sy;
\tcin >> n >> m;
\tfor (int i = 1; i <= n; i++)
\t\tfor (int j = 1; j <= m; j++)
\t\t\tcin >> num[i][j];
\tcin >> sx >> sy >> ex >> ey;
\tnum[sx][sy] = false;
\tdfs(sx, sy, 0);
\tif (flag)
\t\tcout << -1;
  return 0;
}