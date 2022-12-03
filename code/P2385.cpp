#include <iostream>
#include <queue>
#include <cstring>
#include <functional>

using namespace std;

int mz[40][40], dist[40][40];

struct AC {
  int x, y;
  AC() {}
  AC(int x, int y) : x(x) {
    this->y = y;
  }
};

int main() {
  memset(dist, 127, sizeof dist);
  int n, m, c, d, sx, sy, ex, ey;
  cin >> n >> m >> c >> d;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> mz[i][j];
      if (mz[i][j] == 2)
        mz[i][j] = 0;
      if (mz[i][j] == 3) {
        sx = i;
        sy = j;
      }
      if (mz[i][j] == 4) {
        ex = i;
        ey = j;
      }
    }
  const int dr[][2] = {c, d, -c, d, c, -d, -c, -d, d, c, -d, c, d, -c, -d, -c};
  queue<AC> Q;
  function<void(int, int, int)> record = [&](int x, int y, int step) {
    if (min(x, y) > -1 && x < n && y < m && mz[x][y] && step < dist[x][y]) {
      Q.push(AC(x, y));
      dist[x][y] = step;
    }
  };
  function<void(int, int)> bfs = [&](int x, int y) {
    for (record(x, y, 0); !Q.empty();) {
      auto u = Q.front();
      Q.pop();
      for (auto i : dr) {
        int dx = i[0] + u.x, dy = u.y + i[1];
        record(dx, dy, dist[u.x][u.y] + 1);
      }
    }
  };
  bfs(sx, sy);
  cout << dist[ex][ey];
  return 0;
}