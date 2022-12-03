#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 20003;

bool iscut[Hat_N];
tp dfn[Hat_N], low[Hat_N];
list<tp> g[Hat_N];
tp n;

void dfs(tp x, tp f) {
  static tp NC = 0;
  tp ccnt = 0;
  dfn[x] = low[x] = ++NC;
  for (auto&& i : g[x]) {
    if (!dfn[i]) {
      dfs(i, f);
      low[x] = min(low[x], low[i]);
      if (low[i] >= dfn[x] && x != f) {
        iscut[x] = 1;
      }
      if (x == f) {
        ++ccnt;
      }
    }
    low[x] = min(low[x], dfn[i]);
  }
  if (ccnt >= 2 && x == f) {
    iscut[x] = 1;
  }
}

void tarjan() {
  for (tp i = 1; i <= n; ++i) {
    if (!dfn[i]) {
      dfs(i, i);
    }
  }
}

signed main() {
  tp m;
  cin >> n >> m;
  for (tp u, v; m--; g[u].push_front(v), g[v].push_front(u)) {
    cin >> u >> v;
  }
  tarjan();
  cout << count_if(iscut + 1, iscut + n + 1, [](auto x) -> bool { return x; })
       << '\n';
  for (tp i = 1; i <= n; ++i) {
    if (iscut[i]) {
      cout << i << ' ';
    }
  }
  return 0;
}