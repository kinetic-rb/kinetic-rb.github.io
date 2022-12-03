#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 1003;

char mz[Hat_N][Hat_N];
bool vis[Hat_N][Hat_N], Geted[Hat_N][Hat_N];
tp dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
tp n;

tp dfs(tp x, tp y) {
  vis[x][y] = 1;
  tp sum = 1;
  for (auto&& i : dir) {
    tp dx = x + 0[i], dy = y + 1[i];
    if (dx < 1 || dy < 1 || dx > n || dy > n) {
      continue;
    }
    if (mz[dx][dy] == '#' && !vis[dx][dy]) {
      sum += dfs(dx, dy);
    }
  }
  return sum;
}

tp Get(tp x, tp y) {
  Geted[x][y] = 1;
  tp sum = 4;
  for (auto&& i : dir) {
    tp dx = x + 0[i], dy = y + 1[i];
    if (dx < 1 || dy < 1 || dx > n || dy > n) {
      continue;
    }
    if (mz[dx][dy] == '#') {
      --sum;
      if (!Geted[dx][dy]) {
        sum += Get(dx, dy);
      }
    }
  }
  return sum;
}

signed main() {
  tp MAX = 0, RES = 1145141919810;
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      cin >> mz[i][j];
    }
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      if (mz[i][j] == '#' && !vis[i][j]) {
        MAX = max(MAX, dfs(i, j));
      }
    }
  }
  memset(vis, 0, sizeof vis);
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      if (mz[i][j] == '#' && !vis[i][j] && dfs(i, j) == MAX) {
        RES = min(RES, Get(i, j));
      }
    }
  }
  cout << MAX << ' ' << RES;
  return 0;
}
