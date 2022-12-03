#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using tp = long long;
constexpr tp dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};

tp n, m;
vector<vector<bool>> vis;
vector<vector<char>> v;
vector<vector<pair<tp, tp>>> area;

void dfs(tp x, tp y) {
  area.back().emplace_back(x, y);
  vis[x][y] = 0;
  for (auto&& p : dir) {
    tp dx = x + p[0], dy = y + p[1];
    if (~dx && ~dy && dx < n && dy < m && v[dx][dy] == 'X' && vis[dx][dy]) {
      dfs(dx, dy);
    }
  }
}

tp _calc(pair<tp, tp> x, pair<tp, tp> y) {
  return abs(x.first - y.first) + abs(x.second - y.second);
}

tp calc(tp a) {
  tp MIN = -1ull / 2;
  set<tp> s = {0, 1, 2};
  s.erase(a);
  for (auto&& j : area[*s.begin()]) {
    for (auto&& k : area[*s.rbegin()]) {
      tp min1 = -1ull / 2, min2 = -1ull / 2;
      for (auto&& i : area[a]) {
        min1 = min(min1, _calc(i, j));
        min2 = min(min2, _calc(i, k));
      }
      MIN = min(MIN, min1 + min2);
    }
  }
  return MIN - 2;
}

tp calc() {
  tp MIN = -1ull / 2;
  for (tp i = 0; i < n; ++i) {
    for (tp j = 0; j < m; ++j) {
      tp sum = 0;
      for (auto&& a : area) {
        tp cost = -1ull / 6;
        for (auto&& l : a) {
          cost = min(cost, _calc(make_pair(i, j), l));
        }
        sum += cost - 1;
      }
      MIN = min(MIN, sum);
    }
  }
  return MIN + 1;
}

signed main() {
  scanf("%lld%lld", &n, &m);
  v = vector<vector<char>>(n, vector<char>(m));
  vis = vector<vector<bool>>(n, vector<bool>(m, 1));
  for (auto&& i : v) {
    for (auto&& j : i) {
      cin >> j;
    }
  }
  for (tp i = 0; i < n; ++i) {
    for (tp j = 0; j < m; ++j) {
      if (vis[i][j] && v[i][j] == 'X') {
        area.push_back(vector<pair<tp, tp>>());
        dfs(i, j);
      }
    }
  }
  cout << min({calc(0), calc(1), calc(2), calc()});
  return 0;
}