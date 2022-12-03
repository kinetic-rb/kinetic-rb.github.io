#include <cstring>
#include <iostream>

using namespace std;

int map[101][101], f[101][101], dr[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int R, C;

inline int dfs(int x, int y) {
  if (f[x][y] != -1)
    return f[x][y];
  int ans = 0;
  for (int(&i)[2] : dr) {
    int dx = x + i[0], dy = y + i[1];
    if (dx > -1 && dx < R && dy > -1 && dy < C && map[dx][dy] < map[x][y])
      ans = max(ans, dfs(dx, dy));
  }
  return f[x][y] = ans + 1;
}

int main() {
  int T;
  for (cin >> T; T--; putchar('\n')) {
    memset(f, -1, sizeof f);
    string name;
    int MAX = 0;
    cin >> name >> R >> C;
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        cin >> map[i][j];
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        MAX = max(MAX, dfs(i, j));
    cout << name + ": " << MAX;
  }
  return 0;
}