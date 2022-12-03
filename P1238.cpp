#include <iostream>

using namespace std;

const int dr[][2] = { 0, -1, -1, 0, 0, 1, 1, 0 };
bool num[16][16];

struct CE {
  int x, y;
  CE() {}
  CE(int x, int y) : x(x), y(y) {}
} rec[2000];

int n, m, ex, ey;
bool flag = true;

inline void dfs(int x, int y, int step) {
  if (x == ex && y == ey) {
    printf("(1,1)->");
    for (int i = 1; i < step; i++)
      printf("(%d,%d)->", rec[i].x, rec[i].y);
    printf("(%d,%d)
", x, y);
    flag = false;
    return;
  }
  for (auto& i : dr) {
    int dx = x + i[0], dy = i[1] + y;
    if (min(dx, dy) > 0 && dx <= n && dy <= m && num[dx][dy]) {
      rec[step + 1] = CE(dx, dy);
      num[dx][dy] = false;
      dfs(dx, dy, step + 1);
      num[dx][dy] = true;
    }
  }
}

int main() {
  int sx, sy;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> num[i][j];
  cin >> sx >> sy >> ex >> ey;
  num[sx][sy] = false;
  dfs(sx, sy, 0);
  if (flag)
    cout << -1;
  return 0;
}