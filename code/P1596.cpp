#include <iostream>

using namespace std;

const int dr[][2] = { -1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1 };
bool mz[1001][1001];

inline void dfs(int x, int y) {
  mz[x][y] = false;
  for (auto& i : dr) {
    int dx = x + i[0], dy = i[1] + y;
    if (mz[dx][dy])
      dfs(dx, dy);
  }
}

int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      mz[i][j] = c == 'W';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mz[i][j]) {
        dfs(i, j);
        cnt++;
      }
  cout << cnt;
  return 0;
}