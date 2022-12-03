#include <iostream>
#include <vector>

using namespace std;
using tp = int_fast32_t;
constexpr tp Hat_N = 153;

tp p[Hat_N], v[Hat_N], t, f[Hat_N];
vector<tp> graph[Hat_N];

bool dfs(tp x) {
  if (v[x] ^ t) {
    v[x] = t;
    for (auto&& i : graph[x]) {
      if (!p[i] || dfs(p[i])) {
        p[i] = x;
        return 1;
      }
    }
  }
  return 0;
}

signed main() {
  tp n, m, cnt = 0;
  cin >> n >> m;
  for (tp i = 1; i <= m; ++i) {
    tp x, y;
    cin >> x >> y;
    graph[x].push_back(y);
  }
  for (t = 1; t <= n; ++t) {
    dfs(t);
  }
  for (tp i = 1; i <= n; ++i) {
    if (p[i]) {
      f[p[i]] = i;
    }
  }
  for (tp i = 1; i <= n; ++i) {
    if (!p[i]) {
      ++cnt;
      for (tp j = i; j; j = f[j]) {
        cout << j << ' ';
      }
      cout << '\n';
    }
  }
  cout << cnt;
  return 0;
}