#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <vector>
#define co(exp) \
  if (exp) {    \
    puts("No"); \
    return 0;   \
  }

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 1e5 + 3;

tp indeg[Hat_N], outdeg[Hat_N], arc[Hat_N];
list<tp> tar;
vector<tp> g[Hat_N];

void dfs(tp x) {
  for (tp i = arc[x]; i < g[x].size(); i = arc[x]) {
    arc[x] = i + 1;
    dfs(g[x][i]);
  }
  tar.push_front(x);
}

signed main() {
  bool ibo = 0, obi = 0;
  tp n, m, start = 1;
  cin >> n >> m;
  for (tp u, v; m--; g[u].push_back(v)) {
    cin >> u >> v;
    ++indeg[v];
    ++outdeg[u];
  }
  for (tp i = 1; i <= n; ++i) {
    stable_sort(g[i].begin(), g[i].end());
    if (indeg[i] > outdeg[i]) {
      co(ibo || indeg[i] - outdeg[i] != 1);
      ibo = 1;
    } else if (outdeg[i] > indeg[i]) {
      co(obi || outdeg[i] - indeg[i] != 1);
      obi = 1;
      start = i;
    }
  }
  co(ibo ^ obi);
  dfs(start);
  for (auto&& i : tar) {
    cout << i << ' ';
  }
  return 0;
}