#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 10003, Hat_M = 1e5 + 3;

bool vis[Hat_N];
tp w[Hat_N], sccno[Hat_N], f[Hat_N], sccw[Hat_N], dfn[Hat_N], low[Hat_N],
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
      sccw[cnt] += w[save];
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

void dp(tp x) {
  if (f[x]) {
    return;
  }
  for (auto&& i : g[x]) {
    dp(i);
    f[x] = max(f[x], f[i]);
  }
  f[x] += sccw[x];
}

signed main() {
  tp m, tar = 0;
  cin >> n >> m;
  for (tp i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  for (tp i = 0; i < m; ++i) {
    cin >> u[i] >> v[i];
    g[u[i]].push_back(v[i]);
  }
  tarjan();
  for (tp i = 1; i <= n; ++i) {
    g[i].clear();
  }
  for (tp i = 0; i < m; ++i) {
    if (sccno[u[i]] != sccno[v[i]]) {
      g[sccno[u[i]]].push_back(sccno[v[i]]);
    }
  }
  for (tp i = 1; i <= cnt; ++i) {
    dp(i);
    tar = max(tar, f[i]);
  }
  cout << tar;
  return 0;
}