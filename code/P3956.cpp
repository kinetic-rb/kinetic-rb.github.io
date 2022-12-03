#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

bool vis[101][101];
int b[101][101], dr[][2] = { 0, 1, 0, -1, 1, 0, -1, 0 }, dist[101][101];
int n, MIN = 0x7fffffff;

inline void dfs(int x, int y, int coin, bool f) {
  if (x + 1 == n and y + 1 == n) {
    MIN = min(MIN, coin);
    return;
  }
  for (auto& i : dr) {
    int dx = x + i[0], dy = y + i[1];
    if (min(dx, dy) > -1 and max(dx, dy) < n and not vis[dx][dy]) {
      if (not b[dx][dy]) {
        if (f and coin + 2 < dist[dx][dy]) {
          vis[dx][dy] = b[dx][dy] = b[x][y];
          dfs(dx, dy, dist[dx][dy] = coin + 2, false);
          vis[dx][dy] = b[dx][dy] = 0;
        } else
          continue;
      } else if (coin + (b[dx][dy] != b[x][y]) < dist[dx][dy]) {
        vis[dx][dy] = true;
        dfs(dx, dy, dist[dx][dy] = coin + (b[dx][dy] != b[x][y]), true);
        vis[dx][dy] = false;
      }
    }
  }
}

int main() {
  memset(dist, 127, sizeof dist);
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    cin >> b[x - 1][y - 1];
    b[x - 1][y - 1]++;
  }
  dfs(0, 0, 0, true);
  cout << (MIN == 0x7fffffff ? -1 : MIN);
  return 0;
}