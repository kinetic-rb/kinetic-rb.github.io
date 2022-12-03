#include <cstring>
#include <iostream>
#include <list>

using namespace std;

char b[2005][2005];
int dr[][2] = {1, 0, 0, 1, -1, 0, 0, -1}, dist[2005][2005];
int n, m;

void bfs(int sx, int sy) {
  list<int> x, y;
  memset(dist, 0x7f, sizeof dist);
  x.emplace_back(sx), y.emplace_back(sy);
  for (dist[sx][sy] = 0; x.size(); x.pop_front(), y.pop_front()) {
    for (const auto& i : dr) {
      int dx = x.front() + i[0], dy = i[1] + y.front();
      if (min(dx, dy) > 0 && dx <= n && dy <= m && b[dx][dy] != '#' &&
          dist[dx][dy] == 0x7f7f7f7f) {
        x.emplace_back(dx);
        y.emplace_back(dy);
        dist[dx][dy] = dist[x.front()][y.front()] + 1;
      }
    }
  }
}

int main() {
  cin.tie(0);
  int sx, sy, ex, ey;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
      if (b[i][j] == 'd') {
        sx = i;
        sy = j;
      } else if (b[i][j] == 'm') {
        ex = i;
        ey = j;
      }
    }
  bfs(sx, sy);
  dist[ex][ey] == 0x7f7f7f7f ? cout << "No Way!" : cout << dist[ex][ey];
  return 0;
}