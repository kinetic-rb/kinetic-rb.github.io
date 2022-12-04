#include <iostream>

using namespace std;

int a[6][6];
int n, m, cnt, fx, fy;

inline void dfs(int x, int y) {
  if (x < 1 || x > n)
    return;
  if (y < 1 || y > m)
    return;
  if (x == fx && y == fy)  {
    cnt++;
    return;
  }
  if (a[x][y] == 1 || a[x][y] == 2)
    return;
  a[x][y] = 1;
  dfs(x + 1, y);
  dfs(x, y + 1);
  dfs(x - 1, y);
  dfs(x, y - 1);
  a[x][y] = 0;
}

int main() {
  int tx, ty, sx, sy, t;
  cin >> n >> m >> t >> sx >> sy >> fx >> fy;
  for (int i = 0; i < t; i++) {
    cin >> tx >> ty;
    a[tx][ty] = 2;
  }
  if (a[fx][fy] == 2) {
    cout << 0;
    return 0;
  }
  dfs(sx, sy);
  cout << cnt;
  return 0;
}