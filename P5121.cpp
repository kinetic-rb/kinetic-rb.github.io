#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using tp = long long;

tp n, k;
vector<vector<pair<tp, tp>>> area;
vector<vector<bool>> vis;
vector<vector<char>> v;
tp dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void dfs(tp x, tp y) {
  area.back().emplace_back(x, y);
  vis[x][y] = 1;
  for (auto&& d : dir) {
    tp dx = x + d[0], dy = y + d[1];
    if (~dx && ~dy && dx < n && dy < 10 && !vis[dx][dy] &&
        v[dx][dy] == v[x][y]) {
      dfs(dx, dy);
    }
  }
}

bool sad() {
  bool nx = 0;
  area.clear();
  vis = vector<vector<bool>>(n, vector<bool>(10, 0));
  for (tp i = 0; i < n; ++i) {
    for (tp j = 0; j < 10; ++j) {
      if (!vis[i][j] && (v[i][j] & 15)) {
        area.push_back(vector<pair<tp, tp>>());
        dfs(i, j);
      }
    }
  }
  for (auto&& i : area) {
    if (i.size() >= k) {
      nx = 1;
      for (auto&& j : i) {
        v[j.first][j.second] = '0';
      }
    }
  }
  for (tp i = n - 2; i >= 0; --i) {
    for (tp j = 0; j < 10; ++j) {
      tp x = i + 1;
      while (x < n && !(v[x][j] & 15)) {
        swap(v[x - 1][j], v[x][j]);
        ++x;
      }
    }
  }
  return nx;
}

signed main() {
  scanf("%lld%lld", &n, &k);
  v.resize(n);
  vis = vector<vector<bool>>(n, vector<bool>(10, 0));
  for (auto&& i : v) {
    i.resize(10);
    for (auto&& j : i) {
      cin >> j;
    }
  }
  while (sad()) {
  }
  for (auto&& i : v) {
    for (auto&& j : i) {
      cout << j;
    }
    cout << '\n';
  }
  return 0;
}