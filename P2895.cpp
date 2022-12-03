#include <iostream>
#include <cstring>

using namespace std;

int map[350][350], dist[350][350];
int m, MIN = 0x7fffffff;

void dfs(int x, int y, int t) {
  if (map[x][y] <= t || t >= MIN || t >= dist[x][y])
    return;
  dist[x][y] = t;
  if (map[x][y] == 0x7f7f7f7f) {
    MIN = min(t, MIN);
    return;
  }
  dfs(x + 1, y, t + 1);
  if (x > 0)
    dfs(x - 1, y, t + 1);
  dfs(x, y + 1, t + 1);
  if (y > 0)
    dfs(x, y - 1, t + 1);
}

int main() {
  memset(map, 0x7f, sizeof map);
  memset(dist, 0x7f, sizeof dist);
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    map[x][y] = min(map[x][y], t);
    map[x + 1][y] = min(map[x + 1][y], t);
    if (x > 0)
      map[x - 1][y] = min(map[x - 1][y], t);
    map[x][y + 1] = min(map[x][y + 1], t);
    if (y > 0)
      map[x][y - 1] = min(map[x][y - 1], t);
  }
  dfs(0, 0, 0);
  cout << (MIN == 0x7fffffff ? -1 : MIN);
  return 0;
}