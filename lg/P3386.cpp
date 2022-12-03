#include <cstring>
#include <iostream>

using namespace std;
using tp = int;
constexpr tp Hat_N = 503;

bool h[Hat_N][Hat_N], use[Hat_N];
tp result[Hat_N];
tp n, m;

bool dfs(tp loc) {
  for (tp i = 1; i <= m; ++i) {
    if (!use[i] && h[loc][i]) {
      use[i] = 1;
      if (!result[i] || dfs(result[i])) {
        result[i] = loc;
        return 1;
      }
    }
  }
  return 0;
}

tp Do() {
  tp cnt = 0;
  for (tp i = 1; i <= n; ++i) {
    memset(use, 0, sizeof use);
    if (dfs(i)) {
      ++cnt;
    }
  }
  return cnt;
}

signed main() {
  tp e;
  cin >> n >> m >> e;
  for (tp u, v; e--; h[u][v] = 1) {
    cin >> u >> v;
  }
  cout << Do();
  return 0;
}