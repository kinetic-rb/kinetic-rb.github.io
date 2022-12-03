#include <iostream>
#include <list>

using namespace std;
using vt = long long;
constexpr vt Hat_S = 103;

struct Star {
  vt x, y, size;

  Star() = default;
  Star(vt x, vt y, vt size) : x(x), y(y), size(size) {}
};

char mp[Hat_S][Hat_S];
bool vis[Hat_S][Hat_S];
vt n, m;

vt dfs(vt x, vt y, vt step) {
  if (x - step < 1 || x + step > n || y - step < 1 || y + step > m) {
    return step - 1;
  }
  if (mp[x - step][y] == '*' && mp[x + step][y] == '*' &&
      mp[x][y - step] == '*' && mp[x][y + step] == '*') {
    vis[x - step][y] = vis[x + step][y] = vis[x][y - step] = vis[x][y + step] =
        vis[x][y] = true;
    return dfs(x, y, step + 1);
  }
  return step - 1;
}

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  list<Star> res;
  cin >> n >> m;
  for (vt i = 1; i <= n; ++i) {
    for (vt j = 1; j <= m; ++j) {
      cin >> mp[i][j];
    }
  }
  for (vt i = 2; i < n; ++i) {
    for (vt j = 2; j < m; ++j) {
      if (mp[i][j] == '*') {
        if (vt size = dfs(i, j, 1); size) {
          res.emplace_back(i, j, size);
        }
      }
    }
  }
  for (vt i = 1; i <= n; ++i) {
    for (vt j = 1; j <= m; ++j) {
      if (mp[i][j] == '*' && !vis[i][j]) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << res.size() << '\n';
  for (auto&& [x, y, size] : res) {
    cout << x << ' ' << y << ' ' << size << '\n';
  }
  return 0;
}