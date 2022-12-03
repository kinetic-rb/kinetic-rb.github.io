#include <iostream>

using namespace std;

const int dr[][2] = { -1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1 };
bool mz[1001][1001];

inline void dfs(int x, int y) {
\tmz[x][y] = false;
\tfor (auto& i : dr) {
\t\tint dx = x + i[0], dy = i[1] + y;
\t\tif (mz[dx][dy])
\t\t\tdfs(dx, dy);
\t}
}

int main() {
\tint n, m, cnt = 0;
\tcin >> n >> m;
\tfor (int i = 0; i < n; i++)
\t\tfor (int j = 0; j < m; j++) {
\t\t\tchar c;
\t\t\tcin >> c;
\t\t\tmz[i][j] = c == 'W';
\t\t}
\tfor (int i = 0; i < n; i++)
\t\tfor (int j = 0; j < m; j++)
\t\t\tif (mz[i][j]) {
\t\t\t\tdfs(i, j);
\t\t\t\tcnt++;
\t\t\t}
\tcout << cnt;
  return 0;
}