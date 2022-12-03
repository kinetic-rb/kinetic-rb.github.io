#include <cstring>
#include <iostream>

using namespace std;
using tp = int_fast64_t;
constexpr tp Hat_N = 203;

bool mz[Hat_N][Hat_N];
tp use[Hat_N], res[Hat_N];
tp n, rd;

bool dfs(tp x) {
  if (use[x] == rd) {
    return 0;
  }
  use[x] = rd;
  for (tp i = 1; i <= n; ++i) {
    if (mz[x][i] && (!res[i] || dfs(res[i]))) {
      res[i] = x;
      return 1;
    }
  }
  return 0;
}

void Solve() {
  tp cnt = 0;
  memset(res, 0, sizeof res);
  memset(use, 0, sizeof use);
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      cin >> mz[i][j];
    }
  }
  for (rd = 1; rd <= n; ++rd) {
    if (dfs(rd)) {
      ++cnt;
    }
  }
  puts(cnt == n ? "Yes" : "No");
}

signed main() {
  tp t;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}