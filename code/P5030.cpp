#include <iostream>
#include <list>

using namespace std;
using tp = int_fast32_t;
constexpr tp Hat_N = 203, Hat_S = Hat_N * Hat_N;

bool ct[Hat_N][Hat_N];
tp use[Hat_S], result[Hat_S],
    dir[][2] = {3, 1, 1, 3, 3, -1, 1, -3, -1, -3, -3, -1, -1, 3, -3, 1};
list<tp> g[Hat_S];
tp rd;

bool dfs(tp x) {
  if (use[x] ^ rd) {
    use[x] = rd;
    for (auto&& i : g[x]) {
      if (!result[i] || dfs(result[i])) {
        result[i] = x;
        return 1;
      }
    }
  }
  return 0;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n, m, k;
  cin >> n >> m >> k;
  while (k--) {
    tp x, y;
    cin >> x >> y;
    ct[x][y] = 1;
  }
  k = n * m;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= m; ++j) {
      k -= ct[i][j];
    }
  }
  for (tp i = 1; i <= n; ++ ++i) {
    for (tp j = 1; j <= m; ++j) {
      if (!ct[i][j]) {
        for (auto&& d : dir) {
          tp x = i + d[0], y = j + d[1];
          if (x > 0 && y > 0 && x <= n && y <= m && !ct[x][y]) {
            g[i * m + j].push_back(x * m + y);
            g[x * m + y].push_back(i * m + j);
          }
        }
      }
    }
  }
  for (tp i = 1; i <= n; ++ ++i) {
    for (tp j = 1; j <= m; ++j) {
      ++rd;
      k -= dfs(i * m + j);
    }
  }
  cout << k << '\n';
  return 0;
}