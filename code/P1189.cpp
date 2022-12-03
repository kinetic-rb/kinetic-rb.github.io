#include <cstring>
#include <iostream>

using namespace std;

char map[55][55];
bool vis[55][55];
int n, m, N;

inline void Update(int x, int y, int dx, int dy) {
  map[x][y] = '.';
  for (x += dx, y += dy; x <= n && y <= m && x > 0 && y > 0; x += dx, y += dy) {
    if (map[x][y] == 'X')
      return;
    vis[x][y] = true;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> map[i][j];
  cin >> N;
  for (int i = 0; i < N; i++) {
    string dir;
    int dx = 0, dy = 0;
    cin >> dir;
    if (dir == "NORTH")
      dx = -1;
    else if (dir == "SOUTH")
      dx = 1;
    else if (dir == "EAST")
      dy = 1;
    else
      dy = -1;
    memset(vis, 0, sizeof vis);
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++)
        if (map[j][k] == '*')
          Update(j, k, dx, dy);
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++)
        if (vis[j][k])
          map[j][k] = '*';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      cout << map[i][j];
    cout << '\n';
  }
  return 0;
}