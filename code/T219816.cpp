#include <iostream>
#include <functional>

using namespace std;

int dr[][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char Map[101][101];

int main() {
    ios::sync_with_stdio(false);
  int n, m, cnt = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> Map[i][j];
    }
  function<void(int, int)> dfs = [&](int x, int y) -> void {
    if (min(x, y) > -1 && x < n && y < m && Map[x][y] == '.') {
      cnt++;
      Map[x][y] = '#';
      for (auto i : dr) {
        int dx = x + i[0], dy = y + i[1];
        dfs(dx, dy);
      }
    }
  };
  dfs(0, 0);
  cout << cnt;
  return 0;
}