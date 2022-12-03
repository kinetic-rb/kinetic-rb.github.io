#include <iostream>

using namespace std;

int n, MAX;
const int dr[][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
int mz[101][101];

void dfs(int, int, int);
pair<int, int> getloc(int, int, int, int);

int main() {
  int sx, sy;
  cin >> n >> sx >> sy;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) 
      cin >> mz[i][j];
  mz[sx][sy] = 2;
  dfs(sx, sy, 0);
  cout << MAX;
  return 0;
}

inline void dfs(int x, int y, int lo) {
  MAX = max(MAX, lo);
  for (auto i : dr) {
    int dx = getloc(x, y, i[0], i[1]).first, dy = getloc(x, y, i[0], i[1]).second;
    if (dx > 0 && dy > 0 && dx <= n && dy <= n && !mz[dx][dy] && mz[x + i[0]][y + i[1]] == 1) {
      mz[dx][dy] = 2;
      dfs(dx, dy, lo + max(abs(dy - y), abs(dx - x)));
      mz[dx][dy] = 0;
    }
  }
}


inline pair<int, int> getloc(int x, int y, int px, int py) {
  x += px;
  y += py;
  do {
    x += px;
    y += py;
  } while (x > 0 && y > 0 && x <= n && y <= n && mz[x][y] == 1);
  return make_pair(x, y);
}

/*
1 1 0 1 1 0 1
0 1 1 1 0 1 1
1 1 0 1 1 0 1
1 0 1 1 0 1 1
1 0 1 0 1 1 1
1 1 0 1 1 0 1
1 0 1 1 0 1 0

4  3  2
1  0  1  0
1  0  1  1
0  0  0  0
1  1  0  1
*/