#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#define zero(deg) \
  count_if(deg + 1, deg + cnt + 1, [](bool x) -> bool { return !x; })

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 10003, Hat_M = 5000003;

bool vis[Hat_N];
tp sccno[Hat_N], f[Hat_N], dfn[Hat_N], low[Hat_N], indeg[Hat_N], outdeg[Hat_N],
    u[Hat_M], v[Hat_M];
list<tp> stk;
list<tp> g[Hat_N];
tp n, cnt, top;

void dfs(tp x) {
  static tp NC = 0;
  vis[x] = 1;
  stk.push_back(x);
  dfn[x] = low[x] = ++NC;
  for (auto&& i : g[x]) {
    if (!dfn[i]) {
      dfs(i);
      low[x] = min(low[x], low[i]);
    } else if (vis[i]) {
      low[x] = min(low[x], dfn[i]);
    }
  }
  if (dfn[x] == low[x]) {
    tp save;
    ++cnt;
    do {
      save = stk.back();
      sccno[save] = cnt;
      vis[save] = 0;
      stk.pop_back();
    } while (save != x);
  }
}

void tarjan() {
  for (tp i = 1; i <= n; ++i) {
    if (!dfn[i]) {
      dfs(i);
    }
  }
}

signed main() {
  tp m = 0;
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    for (tp to; cin >> to, to; u[m] = i, v[m] = to) {
      g[i].push_back(to);
      ++m;
    }
  }
  tarjan();
  for (tp i = 1; i <= m; ++i) {
    if (sccno[u[i]] != sccno[v[i]]) {
      ++indeg[sccno[v[i]]];
      ++outdeg[sccno[u[i]]];
    }
  }
  cout << zero(indeg) << '\n' << max(zero(indeg), zero(outdeg));
  return 0;
}