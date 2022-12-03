#include <iostream>
#include <functional>

using namespace std;

int dr[][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char Map[101][101];

int main() {
    ios::sync_with_stdio(false);
\tint n, m, cnt = 0;
\tcin >> n >> m;
\tfor (int i = 0; i < n; i++)
\t\tfor (int j = 0; j < m; j++) {
\t\t\tcin >> Map[i][j];
\t\t}
\tfunction<void(int, int)> dfs = [&](int x, int y) -> void {
\t\tif (min(x, y) > -1 && x < n && y < m && Map[x][y] == '.') {
\t\t\tcnt++;
\t\t\tMap[x][y] = '#';
\t\t\tfor (auto i : dr) {
\t\t\t\tint dx = x + i[0], dy = y + i[1];
\t\t\t\tdfs(dx, dy);
\t\t\t}
\t\t}
\t};
\tdfs(0, 0);
\tcout << cnt;
\treturn 0;
}