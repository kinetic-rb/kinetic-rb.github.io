#include "cstring"
#include "iostream"

using namespace std;

bool vis[5520][5520], TV[5520][5520], mp[5520][5520];
const int dr[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int n, m, dn, dm;

inline bool dfs(int x, int y) {
  if (x == -1)
    return dfs(dn - 1, y);
  if (x == dn)
    return dfs(0, y);
  if (y == -1)
    return dfs(x, dm - 1);
  if (y == dm)
    return dfs(x, 0);
  int tox = x % n, toy = y % m;
  if (vis[x][y] || mp[tox][toy])
    return false;
  if (TV[tox][toy])
    return true;
  vis[x][y] = TV[tox][toy] = true;
  for (const auto& i : dr)
    if (dfs(x + i[0], y + i[1]))
      return true;
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
  freopen("^", "r", stdin);
#else
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif  // !ONLINE_JUDGE
  for (int sx, sy; cin >> n >> m; puts((dfs(sx, sy)) ? "Yes" : "No")) {
    dn = n << 1;
    dm = m << 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        mp[i][j] = c == '#';
        if (c == 'S') {
          sx = i;
          sy = j;
        }
      }
    memset(vis, 0, sizeof vis);
    memset(TV, 0, sizeof TV);
  }
  return 0;
}